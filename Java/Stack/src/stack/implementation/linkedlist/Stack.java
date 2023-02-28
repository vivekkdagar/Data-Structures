package stack.implementation.linkedlist;

public class Stack {

    private Node top;

    public Stack() {
        this.top = null;
    }

    private void push(int x) {
        if (top == null) top = new Node(x, null);
        else top = new Node(x, top);
    }

    private void pop() {
        if (top == null) System.out.println("Stack underflow!");
        else top = (top.next == null) ? null : top.next;
    }

    private int peek() {
        return top != null ? top.data : -1;
    }

    @Override
    public String toString() {
        Node t = this.top;
        StringBuilder s = new StringBuilder();
        while (t != null) {
            s.append(t.data);
            if (t.next != null) s.append(", ");
            t = t.next;
        }
        s.append("\n");
        return s.toString();
    }

    private record Node(int data, Stack.Node next) {
    }

    public static void main(String[] args) {
        Stack stk = new Stack();
        stk.push(1);
        stk.push(2);
        stk.push(3);
        stk.pop();
        stk.pop();
        System.out.println(stk);
    }
}
