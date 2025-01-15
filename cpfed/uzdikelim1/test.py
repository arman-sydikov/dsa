import sys

n, q = map(int, sys.stdin.readline().split())
s = sys.stdin.readline()

start = 0

for _ in range(q):
    t, x = map(int, sys.stdin.readline().split())
    
    if t == 1:
        start = (start - x % n + n) % n
    else:
        print(s[(start + x - 1) % n])