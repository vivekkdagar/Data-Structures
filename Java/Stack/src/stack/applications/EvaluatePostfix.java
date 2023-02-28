package stack.applications;

import java.util.Stack;

public class EvaluatePostfix {

    public static int evaluate(String postfix) {
        int result = 0, i = 0;

        // Prepping the stack
        Stack<Integer> stk = new Stack<>();
        stk.push(0);
        stk.push(0);

        while (i < postfix.length()) {
            if (isOperand(postfix.charAt(i))) stk.push(postfix.charAt(i) - '0');
            else {
                int a = stk.peek();
                stk.pop();

                int b = stk.peek();
                stk.pop();

                char op = postfix.charAt(i);

                switch (op) {
                    case '+' -> result = b + a;
                    case '-' -> result = b - a;
                    case '*' -> result = b * a;
                    case '/' -> result = a / b;
                    case '^' -> result = (int) Math.pow(b, a);
                }
                stk.push(result);
            }
            i++;
        }
        return stk.peek();
    }

    public static boolean isOperand(char t) {
        return switch (t) {
            case '+', '-', '*', '/', '^', '(', ')' -> false;
            default -> true;
        };
    }

    public static void main(String[] args) {
        String postfix = "(45*)";
        System.out.println(evaluate(postfix));
    }
}
