#!/usr/bin/python3
""" Function that determines if all "boxes" can be unlocked """


def canUnlockAll(boxes):
    """ Returns True if all boxes have reachable key """
    if not boxes:
        return False
    # Initializes list of unlocked boxes with first box
    key_list = [0]
    # box is index of each box
    for box in range(len(boxes)):
        # test_key is every potential key whether reachable or not
        for test_key in range(box, len(boxes)):
            if test_key in key_list:
                # key is reachable key as found in box where key is in key_list
                for key in boxes[test_key]:
                    if key not in key_list:
                        key_list.append(key)
    # Return if key_list contains key to all locked boxes
    for box_key in range(len(boxes)):
        if box_key not in key_list:
            return False
    return True
