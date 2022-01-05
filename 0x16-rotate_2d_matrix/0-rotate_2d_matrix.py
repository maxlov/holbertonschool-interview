#!/usr/bin/python3


def rotate_2d_matrix(matrix):
    ''' Rotates positions of matrix 90 degrees clockwise'''
    size = len(matrix)
    map = [[[0, 0] for i in range(size)] for j in range(size)]
    empty_matrix = [[0 for i in range(size)] for j in range(size)]
    rotPosY = size - 1
    for x in range(0, size):
        for y in range(0, size):
            map[x][y][0] = y
            map[x][y][1] = rotPosY
        rotPosY -= 1
    for x in range(0, size):
        for y in range(0, size):
            empty_matrix[map[x][y][0]][map[x][y][1]] = matrix[x][y]
    for x in range(0, size):
        for y in range(0, size):
            matrix[x][y] = empty_matrix[x][y]
