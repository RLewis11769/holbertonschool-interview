# Linked List Palindrome (Int)

## Description

A palindrome in a linked list is simply checking whether the value (int n) of the first node is equal to the value of the last node. This example checks ints, although a similar solution should work for strings as well.

Because there is no way to tell how many nodes there are in a linked list, you can't check arr[0] and arr[list_size - 1] as with an array. Converting the linked list to an array was a solution I wrote that did work, but not for the checker because mallocing was not allowed. I could have easily just declared an array of a given size with `int array[100]` for example but I wasn't sure how big to make it and it seemed like cheating to just convert.

However, a memory note to make is that there is no need to check the value of every node. At some point, the pointer to the character to check will pass the midpoint.

For example:
1 -> 17 -> 50 -> 50 -> 17 -> 1

For 1, 17, and 50, the linked list is a palindrome. At that point, the linked list will continue to check 50, 17, and 1. So the efficient solution would be to find the midpoint. Once 1, 17, and 50 are a palindrome, the entire list is.

My initial thought was to find the end and a pointer to the end. At that point, you just have to step backwards from the end using the pointer. Reversing a singly-list creates a pointer from the end to second-to-last node, etc.

This solution worked well for linked lists with an even number of nodes. However, I was unable to find the midpoint for odd-numbered linked lists.

For example:
1 -> 17 -> 50 -> 17 -> 1

This would find 1 and 17 were a palindrome. At that point, I wanted to return with success. However, the program would then check 50 against 17, I think, and return failure.

In the end, I found a recursive solution online. Recursion is the simplest way to work with linked lists. One day I will remember this and make recursion my go-to for them. I just don't like it and keep trying to avoid it.

## lists.h
- Header file containing header guard, definition of node struct, and all prototypes used in helper file and answer file

### 0main.c
- Driver code for testing

### linked_lists.c
- Helper functions to add a node to the end of a list in order to create the linked list, print the value of each node in the list, and free the list
- All of the functions are used by the main file and not in the answer file

### 0-is_palindrome
- Successful attempt!
