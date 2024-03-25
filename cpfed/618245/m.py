def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def count_integer_points(x1, y1, x2, y2):
    diff_x = abs(x2 - x1)
    diff_y = abs(y2 - y1)
    
    gcd_value = gcd(diff_x, diff_y)
    
    # Возвращаем НОД плюс 1
    return gcd_value + 1

# Ввод координат концов отрезка
x1, y1, x2, y2 = map(int, input().split())

# Вывод количества целых точек на отрезке
print(count_integer_points(x1, y1, x2, y2))
