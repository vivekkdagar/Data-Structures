package stack.applications;

import static stack.applications.InfixToPostfix2.convert;

public class Expression {

    private static int solve(String infix) {
        if (MatchParenthesis.isBalanced(infix))
            return EvaluatePostfix.evaluate(convert(infix));
        return -1;
    }

    public static void main(String[] args) {
        String infix = "(2/5)";
        int result = solve(infix);
        System.out.println(result);
    }
}
