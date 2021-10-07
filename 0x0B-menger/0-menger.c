#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * cut_holes - Cuts holes to make a sponge
 *
 * @grid: grid of sponge
 * @level: level of menger sponge
 * @x: x start position of sponge
 * @y: y start position of sponge
 *
 * Return: Cut grid
 */
void cut_holes(char **grid, int level, int x, int y)
{
	int scale, left, right, index, width, up, down;

	if (level == 0)
		return;

	scale = pow(3, level - 1);
	left = scale + x;
	right = (scale * 2) + x;
	up = scale + y;
	down = (scale * 2) + y;

	for (index = left; index < right; index++)
		for (width = up; width < down; width++)
			grid[index][width] = ' ';

	for (index = 0 + x; index <= scale * 2 + x; index += scale)
		for (width = 0 + y; width <= scale * 2 + y; width += scale)
			cut_holes(grid, level - 1, index, width);
}

/**
 * menger - Prints out a menger sponge
 *
 * @level: level of menger sponge
 *
 * Return: Nothing
 */
void menger(int level)
{
	char **grid;
	int size, index, width;

	if (level < 0)
		return;

	size = pow(3, level);

	grid = malloc(size * sizeof(char *));

	for (index = 0; index < size; index++)
		grid[index] = malloc(size * sizeof(char) + 1);

	for (index = 0; index < size; index++)
	{
		for (width = 0; width < size; width++)
			grid[index][width] = '#';
		grid[index][width] = '\0';
	}

	cut_holes(grid, level, 0, 0);

	for (index = 0; index < size; index++)
	{
		printf("%s\n", grid[index]);
		free(grid[index]);
	}
	free(grid);
}
