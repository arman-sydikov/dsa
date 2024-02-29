# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507410/problem/B
# author: Arman Sydikov

# Read n from input
x, k, c = [int(x) for x in input().split()]

cycles = int(c / (3*x + 3 + k))
left = c - cycles * (3*x + 3 + k)

laps = cycles * 3

# First lap
if left - x >= 0:
    left -= x
    laps += 1

# Second lap
if left - (x + 1) >= 0:
    left -= x + 1
    laps += 1

# Third lap
if left - (x + 2) >= 0:
    left -= x + 2
    laps += 1

# Write answer
print(laps)