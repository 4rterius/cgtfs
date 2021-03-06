#include "file_utils.h"

int read_header(FILE *fp, char ***field_names) {
    char **tmp_field_names;
    char header[LINE_MAX_LEN];
    char h_field[LINE_MAX_LEN];
    int h_field_index = 0;
    int h_field_len = 0;

    if (fp == NULL) {
        *field_names = NULL;
        return -1;
    }

    *field_names = malloc(sizeof(char *));
    if (*field_names == NULL) {
        return -1;
    }
    memset(h_field, 0, LINE_MAX_LEN);

    if (fgets(header, LINE_MAX_LEN, fp) == NULL) {
        free(*field_names);
        *field_names = NULL;
        return -1;
    }

    char chr;
    int chr_pos = 0;

    while ((chr = header[++chr_pos - 1])) {
        if (chr == ',' || chr == '\n') {
            tmp_field_names = realloc(*field_names, (h_field_index + 1) * sizeof(char *));
            if (tmp_field_names == NULL) {
                free_cstr_arr(*field_names, h_field_index);
                *field_names = NULL;
                return -1;
            }
            *field_names = tmp_field_names;
            (*field_names)[h_field_index] = strdup(h_field);

            if ((*field_names)[h_field_index] == NULL) {
                free_cstr_arr(*field_names, h_field_index);
                *field_names = NULL;
                return -1;
            }

            memset(h_field, 0, LINE_MAX_LEN);
            h_field_len = 0;
            h_field_index++;
        } else if (chr != '\n' && chr != '\r') {
            h_field[++h_field_len - 1] = chr;
        }
    }

    return h_field_index;
}

int read_record(FILE *fp, const int fields_number, char ***record_values) {
    char record[LINE_MAX_LEN];
    char r_field[LINE_MAX_LEN];
    int r_field_index = 0;
    int r_field_len = 0;
    int in_quotes = 0;  // to ignore commas in "dbl_quoted" field values

    if (fields_number < 0) {
        *record_values = NULL;
        return -1;
    }

    if (fp == NULL) {
        *record_values = NULL;
        return -1;
    }

    memset(r_field, 0, LINE_MAX_LEN);

    *record_values = malloc(fields_number * sizeof(char *));
    if (*record_values == NULL) {
        return -1;
    }
    for (unsigned i = 0; i < fields_number; i++)
        (*record_values)[i] = strdup("");

    if (!fgets(record, LINE_MAX_LEN, fp)) {
        free_cstr_arr(*record_values, fields_number);
        *record_values = NULL;
        return -1;
    }

    char chr;
    int chr_pos = 0;
    int record_len = strlen(record);  // In theory, is guaranteed to have null-terminator, as
                                      // fgets() automatically applies one.
                                      // If not, pls PR or drop maintainer(s) a line.

    strcat(record, "\n");  // fixes the error that happens when the last record isn't followed by a newline
                           // (then the last record field fails to be parsed)

    while ((chr = record[++chr_pos - 1])) {
        if (chr == '"') {
            if (in_quotes == 0) {
                in_quotes = 1;
            } else {
                if (chr_pos < record_len && record[chr_pos] == '"') {
                    r_field[++r_field_len - 1] = '"';
                    chr_pos++;
                } else {
                    in_quotes = 0;
                }
            }
        } else if ((chr == ',' || chr == '\n') && !in_quotes && r_field_index < fields_number) {
            free((*record_values)[r_field_index]);
            (*record_values)[r_field_index] = strdup(r_field);

            if ((*record_values)[r_field_index] == NULL) {
                free_cstr_arr(*record_values, r_field_index);
                *record_values = NULL;
                return -1;
            }

            memset(r_field, 0, LINE_MAX_LEN);
            r_field_len = 0;
            r_field_index++;
        } else if (chr != '\n' && chr != '\r') {
            r_field[++r_field_len - 1] = chr;
        }
    }
    return 1;
}

int count_lines(FILE *fp) {
    int lines = 0;
    int ch_count = -1;
    int ch;

    fpos_t orig_pos;

    if (fp == NULL)
        return -1;

    fgetpos(fp, &orig_pos);
    rewind(fp);

    do {
        ch = fgetc(fp);
        ch_count++;
        if (ch == '\n')
            lines++;
    } while (ch != EOF);

    fsetpos(fp, &orig_pos);

    if (ch_count > 0)
        lines++;

    if (ferror(fp) != 0)
        return -1;

    return lines;
}

int list_txt_files(const char *dir_path, char ***file_names) {
    #ifdef __unix__
        return __list_txt_files__unix(dir_path, file_names);
    #endif
    #ifdef _WIN32
        return __list_txt_files__win(dir_path, file_names);
    #endif
    return -1;
}

#ifdef __unix__
int __list_txt_files__unix(const char *dir_path, char ***file_names) {
    int count = 0;
    char *dotpos = NULL;
    char **tmp_file_names;

    struct dirent *dir_entry;
    DIR *dir_ptr;

    dir_ptr = opendir(dir_path);
    if (dir_ptr == NULL) {
        *file_names = NULL;
        return -1;
    }

    *file_names = malloc(sizeof(char *));

    if (*file_names == NULL) {
        free(*file_names);
        closedir(dir_ptr);
        return -1;
    }

    while ((dir_entry = readdir(dir_ptr))) {
        // https://stackoverflow.com/a/10347734
        dotpos = strrchr(dir_entry->d_name, '.');
        if (dotpos && !strcmp(dotpos, ".txt")) {
            tmp_file_names = realloc(*file_names, (count + 1) * sizeof(char *));
            if (tmp_file_names == NULL) {
                free_cstr_arr(*file_names, count);
                *file_names = NULL;
                return -1;
            }
            *file_names = tmp_file_names;
            (*file_names)[count] = strdup(dir_entry->d_name);
            if ((*file_names)[count] == NULL) {
                free_cstr_arr(*file_names, count);
                *file_names = NULL;
                closedir(dir_ptr);
                return -1;
            }
            count++;
        }
    }

    closedir(dir_ptr);
    return count;
}
#endif

#ifdef _WIN32
int __list_txt_files__win(const char *dir_path, char ***file_names) {
    int count = 0;
    char *dotpos = NULL;
    char **tmp_file_names;

    // OMFG MICROSOFT WHYYYY

    WIN32_FIND_DATA find_data;
    TCHAR search_dir_path[MAX_PATH];
    HANDLE h_find = INVALID_HANDLE_VALUE;
    size_t length_of_arg;
    unsigned long err = 0;

    StringCchLength(dir_path, MAX_PATH, &length_of_arg);
    if (length_of_arg > (MAX_PATH - 3))
        return -1;

    StringCchCopy(search_dir_path, MAX_PATH, dir_path);
    StringCchCat(search_dir_path, MAX_PATH, TEXT("\\*"));

    h_find = FindFirstFile(search_dir_path, &find_data);
    if (h_find == INVALID_HANDLE_VALUE)
        return -1;

    *file_names = malloc(sizeof(char *));
    if (*file_names == NULL) {
        FindClose(h_find);
        free(*file_names);
        *file_names = NULL;
        return -1;
    }
    do {
        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;

        // https://stackoverflow.com/a/10347734
        dotpos = strrchr(find_data.cFileName, '.');
        if (dotpos && !strcmp(dotpos, ".txt")) {
            tmp_file_names = realloc(*file_names, (count + 1) * sizeof(char *));
            if (tmp_file_names == NULL) {
                free_cstr_arr(*file_names, count);
                *file_names = NULL;
                return -1;
            }
            *file_names = tmp_file_names;
            (*file_names)[count] = strdup(find_data.cFileName);
            if ((*file_names)[count] == NULL) {
                free_cstr_arr(*file_names, count);
                *file_names = NULL;
                FindClose(h_find);
                return -1;
            }
            count++;
        }
    } while (FindNextFile(h_find, &find_data) != 0);

    err = GetLastError();
    if (err != ERROR_NO_MORE_FILES)
        return -1;

    FindClose(h_find);

    // shameless copypaste from
    // https://docs.microsoft.com/en-us/windows/win32/fileio/listing-the-files-in-a-directory

    return count;
}
#endif
