def power_mod(a, b, c):
    result = 1
    a = a % c  # Сначала находим остаток от деления a на c

    while b > 0:
        # Если b - нечетное число, умножаем результат на a и находим остаток по модулю c
        if b % 2 == 1:
            result = (result * a) % c

        # Уменьшаем степень b вдвое и находим остаток от деления a^2 на c
        a = (a * a) % c
        b //= 2

    return result

# Ввод a, b, c
a, b, c = map(int, input().split())

# Вывод значения a^b по модулю c
print(power_mod(a, b, c))
