import java.util.Arrays;

public class LinearSearch {

    // Метод для линейного поиска
    public static int linearSearch(int[] arr, int target) {
        // Последовательно проверяем каждый элемент массива
        for (int i = 0; i < arr.length; i++) {
            // Если текущий элемент равен искомому
            if (arr[i] == target) {
                return i; // Возвращаем индекс элемента
            }
        }
        return -1; // Элемент не найден
    }

    public static void main(String[] args) {
        int[] array = {3, 5, 2, 7, 9, 1, 4};
        int target = 7; // Значение для поиска

        System.out.println("Массив: " + Arrays.toString(array));
        System.out.println("Ищем: " + target);

        // Выполняем поиск
        int result = linearSearch(array, target);

        // Выводим результат поиска
        if (result != -1) {
            System.out.println("Элемент найден на позиции: " + result);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}
