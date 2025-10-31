#include <iostream>
#include <vector>

// Функция сортировки выбором
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    // Последовательно увеличиваем границу отсортированной части
    for (int i = 0; i < n - 1; i++) {
        // Считаем текущую позицию минимальным элементом
        int minIndex = i;

        // Ищем реальный минимальный элемент в неотсортированной части
        for (int j = i + 1; j < n; j++) {
            // Если находим элемент меньше текущего минимума - запоминаем его
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Помещаем минимальный элемент на его правильную позицию
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Функция для отображения массива
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Инициализируем тестовый массив
    std::vector<int> data = {29, 10, 14, 37, 13, 25, 8};
    
    std::cout << "Массив до сортировки: ";
    printArray(data);
    
    // Выполняем сортировку
    selectionSort(data);
    
    std::cout << "Массив после сортировки: ";
    printArray(data);
    
    return 0;
}
