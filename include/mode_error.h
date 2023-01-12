#ifndef _MODE_ERROR_H_
#define _MODE_ERROR_H_

#include "game.h"

void print_array(square *array, uint size);
square *get_row(cgame g, uint i);
square *get_col(cgame g, uint j);
void rotate_array(square *array, uint size);
int get_number(int s);
bool is_consecutive(square *array, uint size, int current);
bool is_consecutive_grid(cgame g, uint i, uint j);
bool is_array_full(square *array, uint size);
bool is_array_same(square *array1, square *array2, uint size);
bool is_unique_array(cgame g, uint i, uint j);

#endif /* _MODE_ERROR_H_ */