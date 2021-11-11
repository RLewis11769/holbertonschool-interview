#!/usr/bin/python3
""" Function that determines if all "boxes" can be unlocked """


def canUnlockAll(boxes):
    """ Returns True if all boxes have reachable key """
    key_list = set()

    def test_box(box):
        """ Add index of this box to list """
        key_list.add(box)
        for key in boxes[box]:
            if key not in key_list:
                test_box(key)

    # Start with first box
    test_box(0)

    # If all boxes are in set, return True
    return len(key_list) == len(boxes)
