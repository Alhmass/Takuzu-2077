#include "file.h"

FILE *open_file(const char *path) {
    FILE *f = fopen(path, "rb+");
    assert(f);
    return f;
}

void close_file(FILE *file) {
    if (file != NULL)
        fclose(file);
}

static int get_pos(FILE *file, int line, char delim) {
    assert(file);
    for (int i = 0; i < line; i++) {
        while (!feof(file) && fgetc(file) != delim)
            ;
    }
    int pos = ftell(file);
    rewind(file);
    return pos;
}

char *get_line(char *path, int line) {
    FILE *file = open_file(path);
    assert(file);
    int line_size = LINE_SIZE(file, line);
    assert(line_size >= 0);
    char *linebuf = malloc(sizeof(char) * line_size);
    assert(linebuf);
    fseek(file, get_pos(file, line - 1, '\n'), SEEK_SET);
    fgets(linebuf, line_size, file);
    close_file(file);
    return linebuf;
}

bool set_line(char *path, int line, char *nline) {
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

bool set_value(char *path, int line, int value) {
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