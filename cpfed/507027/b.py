# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507027/problem/B

# Read a1, a2, a3, a4 from input
a = [int(x) for x in input().split()]

# Read s from input
s = input()

sum = 0
for i in s:
    sum += a[int(i)-1]

# Write answer
print(sum)
