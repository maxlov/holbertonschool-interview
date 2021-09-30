#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "slide_line.h"

/**
 * slide_line - Slides numbers left or right using 2048 logic
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in line
 * @direction: either left or right
 * Return: 0 on failure 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t pos = 0, target = 0, last_num_pos = 0, end = 0;

	if (direction == SLIDE_RIGHT)
		pos = target = last_num_pos = size - 1;
	else if (direction == SLIDE_LEFT)
		end = size - 1;
	else
		return (0);

	for (; pos != end + direction; pos += direction)
	{
		if (line[pos] != 0 && last_num_pos != pos)
		{
			if (last_num_pos != INT_MAX && line[pos] == line[last_num_pos])
			{
				line[last_num_pos] += line[pos];
				line[pos] = 0;
				last_num_pos = INT_MAX;
				target += direction;
			}
			else if (line[target] == 0)
			{
				line[target] += line[pos];
				line[pos] = 0;
				last_num_pos = target;
			}
			else
			{
				target += direction;
				last_num_pos += direction;
			}
		}
	}
	return (1);
}
