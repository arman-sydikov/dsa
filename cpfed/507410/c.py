# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507410/problem/C
# author: Arman Sydikov

# Read s1,s2,s3 from input
s = [int(x) for x in input().split()]

# Sort array
s.sort()

steps = 0

# Calculate steps between s[1] and s[2]
distance = s[2] - s[1]
fives = int(distance / 5)
# ones = distance - fives * 5
steps += fives
s[1] += fives * 5

# Calculate steps between s[0] and s[2]
distance = s[2] - s[0]
fives = int(distance / 5)
ones = distance - fives * 5
steps += fives + ones
s[0] += fives * 5

m = min(s)
s[0] -= m
s[1] -= m
s[2] -= m

0 0 4
0 1 4 6 7
0  4

# Write answer
print(s)