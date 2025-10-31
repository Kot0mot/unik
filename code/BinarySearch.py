def binary_search(arr, target):
    """
    Функция бинарного поиска.
    Принимает отсортированный массив и искомое значение.
    Возвращает индекс элемента или -1, если не найден.
    """
    left = 0  # Левая граница области поиска
    right = len(arr) - 1  # Правая граница области поиска

    while left <= right:
        # Вычисляем средний индекс
        mid = left + (right - left) // 2  # Предотвращаем переполнение

        # Сравниваем средний элемент с искомым
        if arr[mid] == target:
            return mid  # Элемент найден
        # Если искомое значение меньше среднего элемента
        elif arr[mid] > target:
            right = mid - 1  # Сужаем поиск до левой половины
        else:  # Если искомое значение больше среднего элемента
            left = mid + 1   # Сужаем поиск до правой половины

    return -1  # Элемент отсутствует в массиве

def print_result(arr, target, index):
    """Функция для вывода результата поиска."""
    print(f"Массив: {arr}")
    print(f"Ищем: {target}")
    if index != -1:
        print(f"Элемент найден на позиции: {index}")
    else:
        print("Элемент не найден")

# Пример использования
if __name__ == "__main__":
    sorted_array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 7

    result_index = binary_search(sorted_array, target)
    print_result(sorted_array, target, result_index)
