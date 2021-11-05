#!/usr/bin/python3
""" Function that determines if all "boxes" can be unlocked """


def canUnlockAll(boxes):
    """ Returns True if all boxes have reachable key """
    # Adds 0 to list so will have starting list of keys to add
    key_list = [0]
    # Copies all keys in box 0 to list to start list of keys to check (will be added onto)
    test_key = boxes[0]
    # Follow every key along its path opening boxes until can't anymore
    # key is list of all available keys whether reachable or not
    for key in test_key:
        if key not in key_list:
            # extend adds all keys in each box to list so will have new keys to check
            test_key.extend(boxes[key])
            key_list.append(key)

    # Return if key_list contains key to all locked boxes
    for box_key in range(len(boxes)):
        if box_key not in key_list:
            return False
    return True
