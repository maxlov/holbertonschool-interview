#!/usr/bin/python3
'''n-queens puzzle solver'''

from sys import argv


def validPlacement(board, row, col):
    ''' checks if queen placement is valid'''
    for i in range(row):
        if board[i][col] == 'Q':
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if (board[i][j] == 'Q'):
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while i >= 0 and j < len(board):
        if board[i][j] == 'Q':
            return False
        i -= 1
        j += 1
    return True


def solveNQueen(board, row):
    '''recursively solves queen'''
    if (row == len(board)):
        answer = []
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'Q':
                    answer.append([i, j])
        print(answer)
        return

    for i in range(len(board)):
        if validPlacement(board, row, i):
            board[row][i] = 'Q'
            solveNQueen(board, row + 1)
            board[row][i] = ' '


if len(argv) != 2:
    print("Usage: nqueens N")
    exit(1)

if isinstance(argv[1], int):
    print("N must be a number")
    exit(1)
size = int(argv[1])
if size < 4:
    print("N must be at least 4")
    exit(1)

board = [[0 for x in range(size)] for y in range(size)]
solveNQueen(board, 0)
