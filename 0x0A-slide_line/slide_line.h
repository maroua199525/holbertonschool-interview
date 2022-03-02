#ifndef SLIDE_LINE
#define SLIDE_LINE

/**##### MACROS ######*/
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

/**###### LIBS USED ######*/
#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void direction_right(int *line, size_t size);
void direction_left(int *line, size_t size);

#endif
