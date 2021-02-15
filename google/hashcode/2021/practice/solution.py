# Import standard input/output
from sys import stdin, stdout

# Set input/output files
# stdin = open('a_example.in', 'r')
# stdin = open('b_little_bit_of_everything.in', 'r')
# stdin = open('c_many_ingredients.in', 'r')
# stdin = open('d_many_pizzas.in', 'r')
stdin = open('e_many_teams.in', 'r')
stdout = open('output.out', 'w')

# Read from input file
m, t2, t3, t4 = [int(x) for x in stdin.readline().split()]
# Declare pizzas array
pizzas = []
for i in range(m):
    # Read i-th pizza from input file
    pizza = stdin.readline().split()
    # Remove the number of ingredients
    pizza.pop(0)
    # Add pizza to pizzas array
    pizzas.append(pizza)

# Declare pizza deliveries
deliveries = []

# 
while m >= 3 and t3 > 0:
    t3-=1
    delivery = '3'
    for _ in range(3):
        m-=1
        delivery += ' ' + str(m)
    deliveries.append(delivery)

while m >= 2 and t2 > 0:
    t2-=1
    delivery = '2'
    for _ in range(2):
        m-=1
        delivery += ' ' + str(m)
    deliveries.append(delivery)

# print answer via write
stdout.write(str(len(deliveries)) + '\n')
for delivery in deliveries:
    stdout.write(str(delivery) + '\n')