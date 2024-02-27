import sys
import math

# Read n from input
n = int(input())

l = 1
r = n
while r - l > 1:
    x = math.ceil(r / 2)
    print(x, flush = True)
    if input() == "<":
        r = x - 1
    else:
        l = x

# Write answer
print(r, flush = True)
if input() == ">=":
    print("! " + str(r), flush = True)
else:
    print("! " + str(l), flush = True)
