# Rain

As the daughter of a dam engineer, I feel uniquely qualified to answer this question. In fact, I have attended several levee inspections and am (humbly) a bit of an expert myself. Here are my thoughts:

This is poor engineering. Are these like retention pond walls? Why would you design them like this? Why would you expand them in this way? A much more efficient and cost-effective way to add area to a body of water would be to not do that and instead add a new body of water. Then you wouldn't have to worry about damming off overflow, which you would in fact need to do prior to undergoing a new wall construction process. And what's the point of having a smaller wall in between 2 larger walls at that point?

At least give me some backstory: Am I calculating the actual amount of water in an over-complicated interconnected water system built by a shady governmental contractor? After this, am I calculating actual cost vs kickbacks or total amount of overcharging?

I appreciate realism in my algorithm projects, actually.

## Description

Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.

## Examples

Here's a helpful chart I made demonstrating some of the rules, as I don't consider the above to be a good explanation:

![Rain Demo](https://github.com/RLewis11769/holbertonschool-interview/blob/main/0x00-rain/rain.png)

## Logic

Like [0x0A menger sponge](https://github.com/RLewis11769/holbertonschool-interview/tree/main/0x0A-menger), I stumbled into the final solution to this on accident.

My initial approach was to find the total area and subtract off both whitespace and walls. I thought this would be easier than adding up the area between walls. Finding walls was easy, but finding whitespace required the exact same approach as finding the area, so I switched to the more conventional approach.

If the logic for the last example shown above gave "2" as the result, I would have looped. This would mean saving the height of the current wall until reaching a higher wall, and then multiplying the shorter wall by the number of indices between them. Which is easy enough. I decided to use enumerate at this point which in my opinion was a terrific decision.

However, if I had to save the height of any walls between the two taller walls in order to subtract them off after calculating the area, that's not really a memory-efficient solution. I ended up with nested loops (and bad output) and considered Big O, at which point I decided to find a different way to accomplish my goal. I might consider correcting my logic and adding that solution at some point.

My next thought was: What if I find just the height of "rain" based on the height of the shorter wall and then loop until I hit the next wall? If the array was [1, 0, 0, 3] for example, 1 would be initial potential height. When I reached the next index, I would add 1, and again for the next index for a final solution of 2.

In that way, I would always be focusing on just the height rather than the width as well and would be able to just add an if statement to account for any in-betweener walls. As it turns out, that's not necessary. The easiest way to find the heights of the walls before and after, max, includes the current wall if you account for value errors.

It took a lot of trial and error and going back to the whiteboard to get this point. I wouldn't consider it stellar logic overall. But I'm very pleased with my min/max-based solution. It's very clean and as memory-efficient as I can get it.

## Navigation

0main.py
- Driver code for testing

0-minoperations.py
- Successful attempt!
