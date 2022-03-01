#include "menger.h"

/**
* menger - a function that draws a 2D Menger Sponge
*@level: the level of the Menger Sponge to draw
*Return: void
*/
void menger(int level)
{
	int i, j, size_menger;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}

	size_menger = pow(3, level);
	for (i = 0; i < size_menger; i++)
	{
		for (j = 0; j < size_menger; j++)
			printf("%c", symbol_menger(i, j));
		printf("\n");
	}
}
/**
 * symbol_menger - the symbol used to draw a merge sponge
 * @row: row of the menger sponge
 * @colum: colum of the menger sponge
 * Return: space or #
 */
char symbol_menger(int row, int colum)
{
	while (row || colum)
	{
		if (row % 3 == 1 && colum % 3 == 1)
			return (' ');
		row = row / 3;
		colum = colum / 3;
	}
	return ('#');
}
