#!/usr/bin/python3
""" a module that contain The N queens puzzle challenge"""
import sys


def pos_qn_nqueen(board, pos_qn):
    """search the queens"""
    for x in board:
        if x[1] == pos_qn[1]:
            return False
        if (x[0] + x[1]) == (pos_qn[0] + pos_qn[1]):
            return False
        if (x[0] - x[1]) == (pos_qn[0] - pos_qn[1]):
            return False
    return True


def search_queens(x, N, board):
    """search the queens"""
    if (x == N):
        print(board)
    else:
        for y in range(N):
            pos_qn = [x, y]
            if pos_qn_nqueen(board, pos_qn):
                board.append(pos_qn)
                search_queens(x + 1, N, board)
                board.remove(pos_qn)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if not isinstance(int(sys.argv[1]), int):
        print("N must be a number")
        exit(1)
    N = int(sys.argv[1])
    if (N < 4):
        print("N must be at least 4")
        exit(1)
    lst = []
    search_queens(0, N, lst)
