#ifndef SANDPILES_SUM
#define SANDPILES_SUM


/**********Header file**********/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*********** Function sandpile *****************/
/*static void print_grid_sum(int grid1[3][3], int grid2[3][3]);*/
/*static void print_grid(int grid[3][3]);*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void copy_sandpile(int grad1[3][3], int dest[3][3]);
static void print_grid(int grid[3][3]);
int check_topple(int grid[3][3]);

#endif
