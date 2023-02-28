package stack.applications;

import java.util.Stack;

public class InfixToPostfix {

    private static String convert(String s) {
        StringBuilder postfix = new StringBuilder();

        Stack<Character> stk = new Stack<>();
        int i = 0;

        while (i < s.length()) {
            char t = s.charAt(i);
            if (EvaluatePostfix.isOperand(t)) {
                postfix.append(t);
                i++;
            } else {
                if (stk.empty() || precedence(t) > precedence(stk.peek())) {
                    stk.push(t);
                    i++;
                } else {
                    postfix.append(stk.peek());
                    stk.pop();
                }
            }
        }

        while (!stk.empty()) {
            postfix.append(stk.peek());
            stk.pop();
        }

        return postfix.toString();
    }

    private static int precedence(char t) {
        return switch (t) {
            case '+', '-' -> 1;
            case '*', '/' -> 2;
            default -> 0;
        };
    }

    public static void main(String[] args) {
        String infix = "a+d*f/g";
        System.out.println(convert(infix));
    }
}
