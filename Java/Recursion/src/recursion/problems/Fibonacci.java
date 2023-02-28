package recursion.problems;

import java.util.Arrays;

public class Fibonacci {

    private static int iterative(int n) {
        if (n <= 1) return n;

        int a = 0, b = 1, sum = 0;

        for (int i = 2; i <= n; i++) {
            sum = a + b;
            a = b;
            b = sum;
        }

        return sum;
    }

    private static int recursive(int n) {
        if (n <= 1) return n;
        return recursive(n - 2) + recursive(n - 1);
    }

    // Using memoization
    private static int[] F;

    private static int mem(int n) {
        if (n <= 1) {
            F[n] = n;
            return n;
        } else {
            if (F[n - 2] == -1)
                F[n - 2] = mem(n - 2);
            if (F[n - 1] == -1)
                F[n - 1] = mem(n - 1);
            return F[n - 2] + F[n - 1];
        }
    }

    public static void main(String[] args) {

        // Prepping the array
        F = new int[10];
        Arrays.fill(F, -1);

        System.out.println(mem(2));
    }
}
