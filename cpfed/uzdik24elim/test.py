def f(a):
    b = len(a)
    n = 0
    print(b, 1 << (b - 1))
    for j in range(1 << (b - 1)):
        x = a[0]
        for i in range(b - 1):
            if j & (1 << i):
                x += '+'
            x += a[i + 1]
        n += eval(x) 
    return n
a = input().strip() 
print(f(a))