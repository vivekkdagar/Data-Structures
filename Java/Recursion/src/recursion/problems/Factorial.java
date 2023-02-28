package recursion.problems;

public class Factorial {

    // Recursive factorial of a number
    public static int recursive(int n) {            // Public because this will be used in NCR
        if (n == 0)
            return 1;
        return recursive(n - 1) * n;
    }

    // Iterative factorial
    private static int iterative(int n) {
        int f = 1;
        for (int i = 1; i <= n; i++)
            f *= i;
        return f;
    }

    public static void main(String[] args) {
        System.out.println("Recursive: " + recursive(4));
        System.out.print("Iterative: " + iterative(4));
    }
}
