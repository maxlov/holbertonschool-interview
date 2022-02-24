# #0x1C. Island Perimeter
##  Returns the perimeter of the island described in grid.

* Function: def island_perimeter(grid)
* Return: returns the perimeter of the island described in grid
* grid is a list of list of integers:
    * 0 represents water, 1 represents land
    * Each cell is square, with a side length of 1
    * Cells are connected horizontally/vertically (not diagonally).
    * grid is rectangular, with its width and height not exceeding 100
* The grid is completely surrounded by water
* There is only one island (or nothing).
* The island doesn’t have “lakes”

This script searches for a land tile, then recursively goes through rest of tiles calculating the perimeter.
