# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507410/problem/E
# author: Arman Sydikov

# Read from input
n = int(input())
c = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

c.sort()
a.sort()

exists = True
for i in reversed(range(1, n)):
    if c[i] < a[i+1]:
        exists = False

# Write answer
# print(c)
# print(a)