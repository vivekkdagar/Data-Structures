package recursion.problems;

public class AccumulateNumbers {            // Sum of n numbers
    private static int recursive(int n) {
        if(n == 0) return 0;
        return recursive(n-1) + n;
    }

    private static int iterative(int n) {
        int s = 0;
        for(int i = 1; i <= n; i++)
            s += i;
        return s;
    }

    public static void main(String[] args) {
        System.out.println(recursive(5));
    }
}
