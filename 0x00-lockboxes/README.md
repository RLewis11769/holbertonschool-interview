# Lockboxes

### Description

There are N boxes. Each box contains zero or more keys to access the next box.

Each BOX (idx) has a LIST OF KEYS (boxes[idx]), and each KEY (box[idx][key]) is an integer. If a key at box[idx][key] = 3, that key opens the box with idx 3, the fourth box in the list, and the keys in box[3] are available to be used to open boxes 1-N.

Initially, all the boxes except box 0 start locked.

You can walk back and forth between boxes freely.

Return true if and only if you can enter every box.

### Examples

#### Input: [[1], [2], [3], []]
- Output: True
- Explanation:
	We start in box 0, and pick up key 1.
	We then go to box 1 and pick up key 2.
	We then go to box 2 and pick up key 3.
	We then go to box 3.
	Since we were able to go to every box, we return true.

#### Input: [[1, 3], [3, 0, 1], [2], [0]]
- Output: False
- Explanation:
	We start in box 0 and pick up keys 1 and 3.
	We then go into box 1 and pick up keys 1 and 3. We have both of those keys.
	We then go into box 3 and pick up key 0. We don't need that key.
	We can access boxes 0, 1, and 3, but not 2.

### Navigation

### 0main.py
- Driver code for testing
- Last test (1000 boxes with all keys in each box) fails recursive and loop attempts due to memory issues

### 0-lockboxes.py
- Successful attempt!

### loop.py
- Failed attempt due to memory issues but overall working code
	- My logic-based attempt (other solutions were found online)
	- Looping too many times and hitting max memory limit (aka not very efficient) but I can't figure out how to loop less/break

### recursive.py
- Failed attempt due to memory issues but overall working code
- Recursive depth limit is around 1000 stack frame limit to prevent stack overflow
	- This means that last test in main is designed to prevent recursive solutions
