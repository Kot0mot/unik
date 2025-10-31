#include <iostream>
#include <vector>

// Функция для поддержания свойства max-кучи
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;        // Наибольший элемент как корень
    int left = 2 * i + 1;  // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Рекурсивно heapify для затронутого поддерева
        heapify(arr, n, largest);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение max-кучи из массива
    // Начинаем с последнего узла, имеющего потомков
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Последовательно извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        // Вызываем heapify для уменьшенной кучи
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
