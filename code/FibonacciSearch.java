import java.util.Arrays;

public class FibonacciSearch {

    // Метод для генерации чисел Фибоначчи до F[m] >= n
    public static int findFib(int n) {
        int fib2 = 0; // F(m-2)
        int fib1 = 1; // F(m-1)
        int fib = fib2 + fib1; // F(m)

        // Находим m такое, что F[m] >= n
        while (fib < n) {
            fib2 = fib1;
            fib1 = fib;
            fib = fib2 + fib1;
        }
        return fib; // Возвращаем F[m] >= n
    }

    // Метод поиска Фибоначчи
    public static int fibonacciSearch(int[] arr, int target) {
        int n = arr.length;

        // Находим наименьшее число Фибоначчи >= n
        int fib2 = 0; // F(m-2)
        int fib1 = 1; // F(m-1)
        int fib = fib2 + fib1; // F(m)

        while (fib < n) {
            fib2 = fib1;
            fib1 = fib;
            fib = fib2 + fib1;
        }

        // Смещение для элементов за пределами массива
        int offset = -1;

        // Выполняем поиск
        while (fib > 1) {
            // Вычисляем проверяемый индекс
            int i = Math.min(offset + fib2, n - 1);

            // Если target больше элемента в позиции i
            if (arr[i] < target) {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }
            // Если target меньше элемента в позиции i
            else if (arr[i] > target) {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }
            // Элемент найден
            else {
                return i;
            }
        }

        // Проверяем последний возможный элемент
        if (fib1 == 1 && offset + 1 < n && arr[offset + 1] == target) {
            return offset + 1;
        }

        return -1; // Элемент не найден
    }

    public static void main(String[] args) {
        int[] arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
        int target = 85; // Искомое значение

        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Ищем: " + target);

        int result = fibonacciSearch(arr, target);

        if (result != -1) {
            System.out.println("Элемент найден на позиции: " + result);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}
