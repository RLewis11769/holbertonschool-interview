#!/usr/bin/python3
""" Function that determines minimum number of operations to reach n chars """


def minOperations(n):
    """
    Returns fewest number of operations to result in n number of H characters
    Can only execute "copy all" and "paste"

    Args:
        n: number of H characters
    """
    string = "H"
    ops = 0

    if n <= 1:
        return (0)
    for x in range(n):
        if len(string) == n:
            return (ops)
        elif len(string) < n:
            ops += 1
            copy = string * 2
            if len(copy) == n:
                return (ops + 1)
            else:
                ops += 1
                pasteDoubled = string + copy
                if len(pasteDoubled) == n:
                    return (ops + 1)
                else:
                    ops += 2
                    string += pasteDoubled
        else:
            return (ops - 2)
