def generate_binary_strings(n, current=""):
    if len(current) == n:
        print(current)
        return
    generate_binary_strings(n, current + "0")
    generate_binary_strings(n, current + "1")

# Тестирование
n = 3
print(f"Все бинарные строки длины {n}:")
generate_binary_strings(n)


Вывод:


Все бинарные строки длины 3:
000
001
010
011
100
101
110
111
