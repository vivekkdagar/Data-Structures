package stack.implementation.array;

import java.util.ArrayList;
import java.util.List;

public class Stack {
    private List<Integer> array;
    private final int size;
    private int top;

    public Stack(int size) {
        this.size = size;
        array = new ArrayList<>(size);
        top = -1;
    }

    private void push(int x) {
        if (this.top == this.size - 1)
            System.out.println("Stack overflow!");
        else {
            this.top++;
            array.add(top, x);
        }
    }

    private boolean empty() {
        return this.top == -1;
    }

    private void pop() {
        if (empty())
            System.out.println("Stack underflow!");
        else {
            array.remove(this.top);
            this.top--;
        }
    }

    private int peek() {
        return empty() ? -1 : array.get(array.size() - 1);
    }

    @Override
    public String toString() {
        StringBuilder output = new StringBuilder();
        for (int i = this.top; i >= 0; i--) {
            output.append(this.array.get(i));
            output.append("\n");
        }
        return output.toString();
    }

    public static void main(String[] args) {
        Stack stk = new Stack(10);
        stk.push(1);
        stk.push(2);
        stk.push(3);
        stk.pop();
        stk.pop();
        stk.pop();
        stk.pop();
        System.out.println(stk.peek());
    }
}
