public class EvenCount {
    public static void main(String[] args) {
        int[] arr = {3, 8, 12, 5, 7, 10};
        int count = 0;

        for (int num : arr) {
            if (num % 2 == 0) {
                count++;
            }
        }

        System.out.println("Количество чётных чисел: " + count);
    }
}
