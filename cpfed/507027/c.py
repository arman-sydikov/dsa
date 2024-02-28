# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507027/problem/C

# Read t from input
t = int(input())

for i in range(t):
    # Read n from input
    n = int(input())

    # Amount of odd numbers
    # For example, if n = 4, it has 2 odd numbers: 1 5
    half = int(n/2)

    # Write answer
    if half % 2 == 0:
        print("YES")
        sumEven, sumOdd = 0, 0
        # Print even numbers
        for j in range(half):
            even = 2*j+2
            sumEven += even
            print(even, end=" ")
        # Print odd numbers
        for j in range(half-1):
            odd = 2*j+1
            sumOdd += odd
            print(odd, end=" ")
        # Print last odd numbers
        print(sumEven - sumOdd)
    else:
        print("NO")
