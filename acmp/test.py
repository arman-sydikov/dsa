abc = 'qwertyuiopasdfghjklzxcvbnm'
a=input()
b='qtplm'
for i in a:
    x=abc.find(i)
    print(i, x)
    b+=abc[(x+1)%26]
print(b)