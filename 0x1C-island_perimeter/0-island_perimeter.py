#!/usr/bin/python3
'''functions that returns island perimeter'''


def find_island(grid):
    '''searches map for land tile'''
    for row in range(0, len(grid)):
        for col in range(0, len(grid[row])):
            if grid[row][col] == 1:
                return [col, row]
    return [-1]


def tile_check(grid, land_tiles, position):
    '''check if tile is land'''
    col = position[0]
    row = position[1]
    if grid[row][col] == 1:
        if [col, row] not in land_tiles:
            land_tiles.append([col, row])
        return 0
    return 1


def tile_scan(grid, land_tiles, position):
    '''scan tiles up, left, down, and right of pos'''
    col = position[0]
    row = position[1]
    beaches = 0
    if col != 0:  # left check
        beaches += tile_check(grid, land_tiles, [col - 1, row])
    else:
        beaches += 1
    if col != len(grid[0]) - 1:  # right check
        beaches += tile_check(grid, land_tiles, [col + 1, row])
    else:
        beaches += 1
    if row != 0:  # up check
        beaches += tile_check(grid, land_tiles, [col, row - 1])
    else:
        beaches += 1
    if row != len(grid) - 1:  # down check
        beaches += tile_check(grid, land_tiles, [col, row + 1])
    else:
        beaches += 1
    return beaches


def island_perimeter(grid):
    '''goes over island and adds up perimeter'''
    perimeter = 0
    land_tiles = []
    land_tiles.append(find_island(grid))
    if land_tiles[0] == [-1]:
        return perimeter
    for position in land_tiles:
        perimeter += tile_scan(grid, land_tiles, position)
    return perimeter
