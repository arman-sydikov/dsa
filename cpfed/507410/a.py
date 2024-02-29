# https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/507410/problem/0
# author: Arman Sydikov

# Read n from input
n = int(input())

# Calculate hour
hh = 11 - 6 + n

# Fix minus hour
if hh < 0:
    hh = 24 + hh

# Add 0 prefix if hour is less than 10
answer = str(hh) + ":00"
if len(answer) < 5:
    answer = "0" + answer

# Write answer
print(answer)