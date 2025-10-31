import java.util.Arrays;

public class ShellSort {

    // Метод для сортировки Шелла
    public static void shellSort(int[] arr) {
        int n = arr.length;

        // Начинаем с большого интервала и уменьшаем его
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Выполняем сортировку вставками для этого интервала
            for (int i = gap; i < n; i++) {
                // Запоминаем текущий элемент
                int current = arr[i];
                int j;

                // Сдвигаем элементы, которые больше текущего
                for (j = i; j >= gap && arr[j - gap] > current; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                // Вставляем текущий элемент на правильную позицию
                arr[j] = current;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 34, 54, 2, 3};

        System.out.println("Исходный массив: " + Arrays.toString(arr));

        shellSort(arr);

        System.out.println("Отсортированный массив: " + Arrays.toString(arr));
    }
}
