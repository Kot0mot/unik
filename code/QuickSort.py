def partition(arr, low, high):
    """
    Функция разбиения массива для быстрой сортировки.
    Выбирает последний элемент как опорный.
    Возвращает индекс, на котором оказался опорный элемент.
    """
    pivot = arr[high]  # Опорный элемент - последний
    i = low - 1        # Индекс для элементов меньше опорного

    for j in range(low, high):
        # Если текущий элемент меньше или равен опорному
        if arr[j] <= pivot:
            i += 1       # Сдвигаем индекс меньших элементов
            arr[i], arr[j] = arr[j], arr[i]  # Обмен элементов

    # Помещаем опорный элемент на правильную позицию
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1  # Возвращаем позицию опорного элемента

def quick_sort(arr, low, high):
    """
    Основная функция быстрой сортировки.
    Сортирует массив arr от индекса low до high (включительно).
    """
    if low < high:
        # Получаем индекс разбиения
        pivot_index = partition(arr, low, high)

        # Рекурсивно сортируем элементы до и после разбиения
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)

def print_array(arr):
    """Функция для вывода массива."""
    print(*arr)

# Пример использования
if __name__ == "__main__":
    # Создаем тестовый массив
    array = [10, 7, 8, 9, 1, 5]

    print("Исходный массив:")
    print_array(array)

    # Сортируем массив
    quick_sort(array, 0, len(array) - 1)

    print("Отсортированный массив:")
    print_array(array)
