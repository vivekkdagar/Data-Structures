package recursion.types;

public class Indirect {

    // Indirect recursion: One recursive function calls another recursive function and the other calls the previous one.
    private static void fun_A(int n) {
        if (n > 0) {
            System.out.print(n + " ");
            fun_B(n - 1);
        }
    }

    private static void fun_B(int n) {
        if (n > 1) {
            System.out.print(n + " ");
            fun_A(n / 2);
        }
    }

    public static void main(String[] args) {
        fun_A(20);
    }
}
