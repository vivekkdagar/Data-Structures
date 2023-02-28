package recursion.problems;

public class TaylorSeries {

    // Method 1
    private static double p = 1, f = 1;

    private static double e(int x, int n) {
        double r;

        if (n == 0) return 1;
        r = e(x, n - 1);
        p *= x;
        f *= n;
        return r + p / f;
    }

    // Method 2
    private static double s;

    private static double horner(int x, int n) {
        if (n == 0) return s;
        s = 1 + x * s / n;
        return horner(x, n - 1);
    }

    // Method 3
    private static double iterative(int x, int n) {
        double s = 1, num = 1, den = 1;
        for (int i = 1; i <= n; i++) {
            num *= x;
            den *= i;
            s += num / den;
        }
        return s;
    }

    public static void main(String[] args) {
        System.out.println(e(2, 10));
        System.out.println(horner(2, 10));
        System.out.println(iterative(2, 10));
    }
}
