package recursion.problems;

public class TowerOfHanoi {

    private static void TOH(int n, int A, int B, int C) {
        if (n > 0) {
            TOH(n - 1, A, C, B);
            System.out.println("Move a disc from " + A + " to " + C);
            TOH(n - 1, B, A, C);
        }
    }

    public static void main(String[] args) {
        TOH(2,1,2,3);
    }
}
