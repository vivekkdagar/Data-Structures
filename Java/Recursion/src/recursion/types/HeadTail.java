package recursion.types;

public class HeadTail {

    // Tail recursion: recursive call is the last statement in the function
    private static void tail(int n) {
        if (n > 0) {
            System.out.print(n + " ");
            tail(n - 1);
        }
    }

    // Head recursion: recursive call is the first statement in the function
    private static void head(int n) {
        if (n > 0) {
            head(n - 1);
            System.out.print(n + " ");
        }
    }

    public static void main(String[] args) {
        head(5);
        System.out.println();
        tail(5);
    }
}
