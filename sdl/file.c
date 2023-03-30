#include "file.h"

FILE *open_file(const char *path) {
    assert(path);
    FILE *f = fopen(path, "rb+");
    assert(f);
    return f;
}

void close_file(FILE *file) {
    if (file != NULL)
        fclose(file);
}

static int get_pos(FILE *file, int line) {
    assert(file);
    for (int i = 0; i < line; i++) {
        while (!feof(file) && fgetc(file) != '\n')
            ;
    }
    int pos = ftell(file);
    rewind(file);
    return pos;
}

static int get_line_nb(char *path, char *searched) {
    assert(path);
    assert(searched);
    FILE *file = open_file(path);
    char buffer[256];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        count++;
        if (strstr(buffer, searched) != NULL) {
            close_file(file);
            return count;
        }
    }
    close_file(file);
    return -1;
}

static int get_set_size(char *path, int line) {
    assert(path);
    FILE *file = open_file(path);
    char buffer[256];
    char setting[256];
    assert(file);
    fseek(file, get_pos(file, line - 1), SEEK_SET);
    fscanf(file, "%s %s", buffer, setting);
    close_file(file);
    return strlen(setting);
}

char *get_line(char *path, int line) {
    assert(path);
    FILE *file = open_file(path);
    assert(file);
    int line_size = LINE_SIZE(file, line);
    assert(line_size >= 0);
    char *linebuf = malloc(sizeof(char) * line_size);
    assert(linebuf);
    fseek(file, get_pos(file, line - 1), SEEK_SET);
    fgets(linebuf, line_size, file);
    close_file(file);
    return linebuf;
}

char *get_setting(char *path, char *setting) {
    assert(path);
    assert(setting);
    int line = get_line_nb(path, setting);
    assert(line >= 0);
    int setting_size = get_set_size(path, line);
    assert(setting_size >= 0);
    char buf[256];
    FILE *file = open_file(path);
    char *set = malloc(sizeof(char) * setting_size);
    fseek(file, get_pos(file, line - 1), SEEK_SET);
    fscanf(file, "%s %s", buf, set);
    close_file(file);
    return (set);
}

bool set_line(char *path, int line, char *nline) {
    assert(path);
    assert(nline);
    FILE *file = open_file(path);
    char tempFile[] = "temp.txt";
    FILE *tmp = fopen(tempFile, "a");
    char buffer[255];
    int count = 0;
    assert(tmp);
    while (fgets(buffer, 255, file)) {
        count++;
        if (count != line) {
            if (fprintf(tmp, "%s", buffer) == EOF)
                return false;
        } else if (count == line) {
            if (fprintf(tmp, "%s\n", nline) == EOF)
                return false;
        }
    }
    fclose(tmp);
    close_file(file);
    remove(path);
    rename(tempFile, path);
    return true;
}

bool set_setting(char *path, char *setting, char *value) {
    assert(path);
    assert(value);
    assert(setting);
    int line = get_line_nb(path, setting);
    char *curr_line = get_line(path, line);
    strtok(curr_line, " ");

    size_t len = strlen(curr_line) + strlen(value) + 2;
    char *new_line = malloc(sizeof(char) * len);
    assert(new_line);
    strcpy(new_line, curr_line);
    strcat(new_line, " ");
    strcat(new_line, value);

    bool res = set_line(path, line, new_line);
    free(curr_line);
    free(new_line);
    return res;
}

bool set_value(char *path, int line, int value) {
    assert(path);
    char str[10];
    snprintf(str, sizeof(str), "%d", value);

    char *curr_line = get_line(path, line);
    strtok(curr_line, " ");

    size_t len = strlen(curr_line) + strlen(str) + 2;
    char *new_line = malloc(sizeof(char) * len);
    assert(new_line);
    strcpy(new_line, curr_line);
    strcat(new_line, " ");
    strcat(new_line, str);

    bool res = set_line(path, line, new_line);
    free(curr_line);
    free(new_line);
    return res;
}