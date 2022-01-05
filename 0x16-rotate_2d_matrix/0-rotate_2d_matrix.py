#!/usr/bin/python3
""" Rotates posiitons of matrix """

def rotate_2d_matrix(matrix):
    """ Rotates positions of matrix 90 degrees clockwise """
    size = len(matrix)
    matrixMap = [[[0, 0] for i in range(size)] for j in range(size)]
    empty_matrix = [[0 for i in range(size)] for j in range(size)]
    rotPosY = size - 1
    for x in range(size):
        for y in range(size):
            matrixMap[x][y][0] = y
            matrixMap[x][y][1] = rotPosY
        rotPosY -= 1
    for x in range(size):
        for y in range(size):
            empty_matrix[matrixMap[x][y][0]][matrixMap[x][y][1]] = matrix[x][y]
    for x in range(size):
        for y in range(size):
            matrix[x][y] = empty_matrix[x][y]
