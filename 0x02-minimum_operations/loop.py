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
        # If found, return
        if len(string) == n:
            return (ops)
        # If not found, first copy all
        elif len(string) < n:
            ops += 1
            copy = string * 2
            # If found with single copy, paste - add 1 for second operation
            if len(copy) == n:
                return (ops + 1)
            else:
                # Have already pasted so add one more operation
                ops += 1
                # Then paste same string again and check length to see if found
                pasteDoubled = string + copy
                if len(pasteDoubled) == n:
                    return (ops + 1)
                else:
                    # Have already copy-pasted so start loop again
                    ops += 2
                    string += pasteDoubled
        else:
            # If string is greater than n, remove the last copy-paste
            return (ops - 2)
