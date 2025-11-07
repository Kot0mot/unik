public class BinaryStrings {
    public static void generate(int n, String s) {
        if (s.length() == n) {
            System.out.println(s);
            return;
        }
        generate(n, s + "0");
        generate(n, s + "1");
    }

    public static void main(String[] args) {
        int n = 3;
        System.out.println("Все бинарные строки длины " + n + ":");
        generate(n, "");
    }
}


Вывод:


Все бинарные строки длины 3:
000
001
010
011
100
101
110
