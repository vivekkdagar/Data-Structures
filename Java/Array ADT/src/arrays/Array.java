package arrays;

public class Array {

    private int[] list;
    private int size;
    private int length;

    public Array(int size) {
        this.size = size;
        this.length = 0;
        list = new int[size];
    }

    private boolean empty() {
        return this.length == 0;
    }

    private boolean full() {
        return this.length == this.size - 1;
    }

    private void insert(int index, int value) {
        if (!full()) {
            if (index == this.length)
                this.append(value);
            else if (index >= 0 && index < this.length) {
                for (int i = this.length; i > index; i--)
                    this.list[i] = this.list[i - 1];
                this.list[index] = value;
                this.length++;
            } else
                System.out.println("Invalid Index");
        } else {
            System.out.println("Array full");
        }
    }

    private void append(int value) {
        if (!full())
            this.list[this.length++] = value;
        else
            System.out.println("Array full");
    }

    private void remove(int index) {
        if (index >= 0 && index < this.length) {
            for (int i = index; i < this.length - 1; i++) {
                this.list[i] = this.list[i + 1];
            }
            this.length--;
        } else
            System.out.println("Invalid Index");
    }

    private int get(int index) {
        if (index >= 0 && index < this.length)
            return this.list[index];
        return -1;
    }

    private void set(int index, int value) {
        if (index >= 0 && index < this.length)
            this.list[index] = value;
        else
            System.out.println("Invalid Index");
    }

    private boolean isSorted() {
        for (int i = 0; i < this.length - 1; i++)
            if (this.list[i] > this.list[i + 1])
                return false;
        return true;
    }

    @Override
    public String toString() {
        String s = "[";
        for (int i = 0; i < this.length; i++) {
            s += this.list[i];
            if (i != this.length - 1)
                s += ", ";
        }
        s += "]";
        return s;
    }

    public static void main(String[] args) {
        Array myArray = new Array(5);
        myArray.append(1);
        myArray.append(2);
        myArray.remove(1);
        myArray.remove(0);
        System.out.println(myArray);
    }
}