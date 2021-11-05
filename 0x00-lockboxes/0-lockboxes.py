#!/usr/bin/python3
""" Function that determines if all "boxes" can be unlocked """


def canUnlockAll(boxes):
    """ Returns True if all boxes have reachable key """
    # Create a list of key_list with default box being 0
    key_list = [0]
    # box is index of box
    # list is list of all keys inside each box
    for box, list in enumerate(boxes):
        # idx starts off at current box for each loop so not repeatedly checking
        for idx in range(box, len(boxes)):
            if idx in key_list:
                # Same sort of appending as before
                [key_list.append(key) for key in boxes[idx] if key not in key_list]
        # Attempt to open box that met above else condition
        if box in key_list:
            [key_list.append(key) for key in list if key not in key_list]
        else:
            return False
    return True
