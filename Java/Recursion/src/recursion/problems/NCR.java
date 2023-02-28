package recursion.problems;

public class NCR {

    // Method 1: the simplest way; using factorial
    private static int usingFact(int n, int r) {
        int num = Factorial.recursive(n);
        int den = Factorial.recursive(r) * Factorial.recursive(n - r);
        return num / den;
    }

    // Method 2
    private static int recursive(int n, int r) {
        if (n == r || r == 0) return 1;
        return recursive(n - 1, r - 1) + recursive(n - 1, r);
    }

    public static void main(String[] args) {
        System.out.println(usingFact(2, 1));
        System.out.println(recursive(2, 1));
    }
}
