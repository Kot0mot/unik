#include <iostream>
#include <vector>

// Функция интерполирующего поиска
int interpolationSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0;        // Нижняя граница поиска
    int high = n - 1;   // Верхняя граница поиска

    // Условия для продолжения поиска
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Если границы совпадают
        if (low == high) {
            if (arr[low] == target) return low;
            return -1; // Элемент не найден
        }

        // Вычисляем предполагаемую позицию с помощью интерполяции
        // pos = low + [(target - arr[low]) * (high - low)] / (arr[high] - arr[low])
        int pos = low + (((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low));

        // Проверяем элемент в вычисленной позиции
        if (arr[pos] == target) {
            return pos; // Элемент найден
        }
        // Если искомое значение больше, ищем в правой части
        else if (arr[pos] < target) {
            low = pos + 1;
        }
        // Если искомое значение меньше, ищем в левой части
        else {
            high = pos - 1;
        }
    }
    return -1; // Элемент не найден
}

int main() {
    std::vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int target = 18; // Искомое значение

    std::cout << "Массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\nИщем: " << target << std::endl;

    int result = interpolationSearch(arr, target);

    if (result != -1) {
        std::cout << "Элемент найден на позиции: " << result << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0;
}
