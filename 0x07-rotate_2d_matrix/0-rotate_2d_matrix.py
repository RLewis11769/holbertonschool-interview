#!/usr/bin/python3
""" Function that rotates 2D matrix 90 degrees (counter-clockwise) """

def rotate_2d_matrix(matrix):
    """ Rotate 2D matrix in place by 90 degrees """
    # * means pass all items in list to operation
    # so zip(*matrix) is the same as zip(matrix[0], matrix[1], ...)
    # zip makes a list of tuples from the list of lists
    # And then convert the list of tuples to a list of lists
    # :: is normal slice operator to jump over elements to previous (step/iterator)
    matrix[:] = [list(i) for i in zip(*matrix[::-1])]
