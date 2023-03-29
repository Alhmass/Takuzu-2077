#ifndef FILE_H
#define FILE_H

#include <assert.h>
#include <stdbool.h>

FILE *open_file(char *path);
void close_file(FILE *file);

char *get_line(FILE *file, int line);
char *get_setting(FILE *file, int line);

bool set_value(FILE *file, int line, int value);
bool set_setting(FILE *file, int line, char *value);
bool set_line(FILE *file, int line, char *line);

#endif /* FILE_H */