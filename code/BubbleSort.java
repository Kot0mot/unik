import java.util.Arrays;

public class BubbleSort {

    // Метод для сортировки массива методом пузырька
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped; // Флаг для оптимизации: если не было обменов, массив отсортирован

        // Проходим по всем элементам массива
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            // Последние i элементов уже на своем месте
            for (int j = 0; j < n - i - 1; j++) {
                // Сравниваем соседние элементы
                if (arr[j] > arr[j + 1]) {
                    // Меняем местами, если они стоят в неправильном порядке
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true; // Устанавливаем флаг, если был обмен
                }
            }
            // Если не было обменов, массив отсортирован, можно выйти
            if (!swapped) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Исходный массив: " + Arrays.toString(arr));

        bubbleSort(arr);

        System.out.println("Отсортированный массив: " + Arrays.toString(arr));
    }
}
