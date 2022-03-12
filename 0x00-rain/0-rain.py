#!/usr/bin/python3
""" Calcuates area of rainwater between two walls """


def rain(walls):
    """ Add height of wall on each iteration until it reaches a higher wall """
    if len(walls) < 1:
        return 0

    amount = 0
    for idx, height in enumerate(walls):
        # Find max height of the wall before current (including current)
        before = max(walls[:idx + 1])
        # Find max height of the wall after current (including current)
        after = max(walls[idx:])
        # Add difference between smaller wall and current wall
        amount += min(before, after) - height
    return amount
