#!/usr/bin/python3

def rotate_2d_matrix(matrix):
    size = len(matrix)
    map_matrix = [[[0, 0] for i in range(size)] for j in range(size)]
    empty_matrix = [[0 for i in range(size)] for j in range(size)]
    rotPosY = size - 1
    for x in range(0, size):
        for y in range(0, size):
            map_matrix[x][y][0] = y
            map_matrix[x][y][1] = rotPosY
        rotPosY -= 1
    for x in range(0, size):
        for y in range(0, size):
            empty_matrix[map_matrix[x][y][0]][map_matrix[x][y][1]] = matrix[x][y]
    for x in range(0, size):
        for y in range(0, size):
            matrix[x][y] = empty_matrix[x][y]