#!/usr/bin/python3
""" Function that determines minimum number of operations to reach n chars """


def minOperations(n):
    """
    Returns fewest number of operations to result in n number of H characters
    Can only execute "copy all" and "paste"

    Args:
        n: number of H characters aka number to reach
    """
    if n <= 1:
        return (0)
    factor = 2
    factor_list = []
    # Find prime factors that go into n
    while (n % factor > 0):
        factor += 1
    # After initial factorization, continue through loop until n is 1
    while (n % factor == 0):
        factor_list.append(factor)
        # Check if factor is prime
        n = n / factor
        # No more factors to check so done - go through list and add all index
        if (n == 1):
            for idx in factor_list:
                return (sum(factor_list))
        # Find prime factors higher than initial factor
        while (n % factor > 0):
            factor += 1
    print(list)
