#!/usr/bin/python3


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

    def paste(mains, copieds):
        """
        Returns str

        Args:
            str: str to add to global variable string
        """
        return (mains + copieds)

    def checkString(s, n):
        """
        Returns true if current string has n characters

        Args:
            s: string to check length of
            n: number of characters in s if true
        """
        if len(s) == n:
            return True
        return False

    string = "H"
    ops = 2

    while(1):
        if len(string) == n:
            return ops
        if len(string) > n:
            return 0
        else:
            ops += 1
            copy = copyAll(string)
            checkOrig = checkString(copy, n)
            if checkOrig:
                return ops
            else:
                ops += 1
                pasteDoubled = paste(string, copy)
                checkDoubled = checkString(pasteDoubled, n)
                if checkDoubled:
                    return ops
                else:
                    ops += 1
                    string += pasteDoubled
