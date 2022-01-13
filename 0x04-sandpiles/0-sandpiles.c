#include "sandpiles.h"

/**
  * copy_sandpile - copy two sandpiles
  * @grad1: 2D array
  * @dest: 2D array
  */

void copy_sandpile(int grad1[3][3], int dest[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			dest[i][j] = grad1[i][j];
		}
}
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
  *check_topple - check if it is sandpile or topple
  *@grid: 2D array
  *Return: 1 or 0
  */
int check_topple(int grid[3][3])
{

	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 ; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
*sandpiles_sum - sum of 3x3 grids
*@grid1: 3x3 grid
*@grid2: 3x3 grid
*Return:void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	int gridcopy[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 ; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];

		}
	}
	while (!check_topple(grid1))
	{
		copy_sandpile(grid1, gridcopy);
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (gridcopy[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (i + 1 <= 2)
						grid1[i + 1][j] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
					if (j + 1 <= 2)
						grid1[i][j + 1] += 1;
				}
			}
	}
}
