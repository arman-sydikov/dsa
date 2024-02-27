# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/506992/problem/E

# Read n from input
n = int(input())

xArr = []
yArr = []

# Read x, y from input
for i in range(n):
    x, y = [int(x) for x in input().split()]
    xArr.append(x)
    yArr.append(y)

sum = 0
for i in range(len(xArr)):
    for j in range(i, len(xArr)):
        if i != j:
            sum += abs(xArr[i] - xArr[j])

for i in range(len(yArr)):
    for j in range(i, len(yArr)):
        if i != j:
            sum += abs(yArr[i] - yArr[j])

# Write answer
print(sum)