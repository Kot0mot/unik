#include <iostream>
#include <vector>

// Функция слияния двух отсортированных подмассивов
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1; // Размер левой части
    int rightSize = right - mid;   // Размер правой части

    // Создаем временные массивы для левой и правой частей
    std::vector<int> leftPart(leftSize);
    std::vector<int> rightPart(rightSize);

    // Копируем данные во временные массивы
    for (int i = 0; i < leftSize; i++)
        leftPart[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightPart[j] = arr[mid + 1 + j];

    // Объединяем временные массивы обратно в основной
    int i = 0;    // Индекс левого подмассива
    int j = 0;    // Индекс правого подмассива
    int k = left; // Индекс основного массива

    while (i < leftSize && j < rightSize) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k] = leftPart[i];
            i++;
        } else {
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }

    // Копируем остатки из левого подмассива
    while (i < leftSize) {
        arr[k] = leftPart[i];
        i++;
        k++;
    }

    // Копируем остатки из правого подмассива
    while (j < rightSize) {
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}

// Основная функция сортировки слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Вычисляем среднюю точку
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем левую и правую части
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Объединяем отсортированные части
        merge(arr, left, mid, right);
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
    std::vector<int> array = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Исходный массив: ";
    printArray(array);

    // Выполняем сортировку слиянием
    mergeSort(array, 0, array.size() - 1);

    std::cout << "Отсортированный массив: ";
    printArray(array);

    return 0;
}
