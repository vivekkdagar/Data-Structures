package stack.applications;

import java.util.Stack;

import static stack.applications.EvaluatePostfix.*;

public class InfixToPostfix2 {

    public static String convert(String infix) {
        Stack<Character> stk = new Stack<>();
        StringBuilder postfix = new StringBuilder();

        int i = 0;
        while (i < infix.length()) {
            char t = infix.charAt(i);
            if (isOperand(t)) {
                postfix.append(t);
                i++;
            } else if (!isOperand(t)) {
                if (stk.empty() || outPre(t) > inPre(stk.peek())) {
                    stk.push(t);
                    i++;
                } else if (outPre(t) == inPre(stk.peek())) {
                    stk.pop();
                    i++;
                } else {
                    if (stk.peek() != '(') {
                        postfix.append(stk.peek());
                        stk.pop();
                    }
                }
            }
        }

        while (!stk.empty()) {
            postfix.append(stk.peek());
            stk.pop();
        }
        return postfix.toString();
    }

    private static int outPre(char t) {
        return switch (t) {
            case '+', '-' -> 1;
            case '*', '/' -> 3;
            case '^' -> 6;
            case '(' -> 7;
            case ')' -> 0;
            default -> -1;
        };
    }

    private static int inPre(char t) {
        return switch (t) {
            case '+', '-' -> 2;
            case '*', '/' -> 4;
            case '^' -> 5;
            case '(' -> 0;
            default -> -1;
        };
    }

    public static void main(String[] args) {
        String infix = "(a+((b-f*g)+bc))";
        System.out.println(convert(infix));
    }
}
