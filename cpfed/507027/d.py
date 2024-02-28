# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507027/problem/D

# Read t from input
t = int(input())

for i in range(t):
    # Read n from input
    n = int(input())

    # Read a,b,c from input
    a = input()
    b = input()
    c = input()

    # Compare c with a and b
    exists = False
    for i in range(n):
        if c[i] != a[i] and c[i] != b[i]:
            exists = True

    # Write answer
    if exists:
        print("YES")
    else:
        print("NO")

