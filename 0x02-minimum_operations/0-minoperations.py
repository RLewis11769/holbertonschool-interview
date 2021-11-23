#!/usr/bin/python3
""" Function that determines minimum number of operations to reach n chars """


def minOperations(n):
    """
    Returns fewest number of operations to result in n number of H characters
    Can only execute "copy all" and "paste"

    Args:
        n: number of H characters
    """

    def copyAll(s):
        """
        Returns copy of all characters in string

        Args:
            str: string to duplicate and return
        """
        return (s * 2)

    def paste(str1, str2):
        """
        Returns concatenated strings

        Args:
            str1: first string to concatenate (main string)
            str: second string to concatenate (copied string)
        """
        return (str1 + str2)

    string = "H"
    ops = 0

    for x in range(n):
        if len(string) == n:
            return (ops)
        elif len(string) < n:
            ops += 1
            copy = copyAll(string)
            if len(copy) == n:
                return (ops + 1)
            else:
                ops += 1
                pasteDoubled = paste(string, copy)
                if len(pasteDoubled) == n:
                    return (ops + 1)
                elif len(pasteDoubled) < n:
                    ops += 2
                    string += pasteDoubled
        else:
            return 0
