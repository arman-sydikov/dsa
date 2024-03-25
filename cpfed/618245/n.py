def min_parts_for_cake(n, m):
    return max(n, m) if n != 1 and m != 1 else n * m

# Ввод количества гостей n и m
n, m = map(int, input().split())

# Вывод минимального количества частей для торта
print(min_parts_for_cake(n, m))
