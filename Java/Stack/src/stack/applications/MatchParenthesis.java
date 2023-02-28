package stack.applications;

import java.util.Stack;

public class MatchParenthesis {

    private static boolean isOpening(char t) {
        return switch (t) {
            case '(', '[', '{' -> true;
            default -> false;
        };
    }

    private static boolean isClosing(char t) {
        return switch (t) {
            case ')', ']', '}' -> true;
            default -> false;
        };
    }

    public static boolean isBalanced(String expression) {
        Stack<Character> stk = new Stack<>();

        for (int i = 0; i < expression.length(); i++) {
            char t = expression.charAt(i);
            if (isOpening(t))
                stk.push(t);
            else if (isClosing(t)) {
                if (stk.empty()) return false;

                char s = stk.peek();
                stk.pop();

                int value = Math.abs((int) s - (int) t);
                if (value != 1 && value != 2) return false;
            }
        }
        return stk.empty();
    }

    public static void main(String[] args) {
        String exp = "}";
        System.out.println(isBalanced(exp));
    }
}
