package recursion.problems;

public class Power {

    private static int recursive(int m, int n) {
        if (n == 0) return 1;
        return recursive(m, n - 1) * m;
    }

    private static int optimized(int m, int n) {
        if (n == 0) return 1;

        if (n % 2 == 0) return optimized(m * m, n / 2);

        return m * optimized(m * m, (n - 1) / 2);
    }

    public static void main(String[] args) {
        System.out.println(optimized(9,3));
    }
}
