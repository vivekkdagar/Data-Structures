import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Heap {
    private List<Integer> array;

    public Heap(Integer[] A, int n) {
        array = new ArrayList<>();
        array.addAll(Arrays.asList(A));
        for (int i = (n / 2) - 1; i >= 0; i--)
            minHeapify(i, this.array.size());
    }

    private void minHeapify(int i, int n) {

        // Find left and right children of current node
        int lChild = left(i);
        int rChild = right(i);

        // Assume current node is the smallest
        int smallest = i;

        // if lChild is valid, and it is smaller than the current node
        if (lChild < n && this.array.get(lChild) < this.array.get(smallest))
            smallest = lChild;

        // Similarly for rChild
        if (rChild < n && this.array.get(rChild) < this.array.get(smallest))
            smallest = rChild;

        // If current node is not the smallest, then swap it with the smallest child
        // and recursively call heapify on that child
        if (smallest != i) {
            Collections.swap(this.array, i, smallest);
            minHeapify(smallest, n);
        }
    }

    private int remove() {
        if (array.size() == 0)
            return -1;

        // Smallest element is at the front of the list
        int val = this.array.get(0);

        // Swap it with the last element
        int lastIndex = this.array.size() - 1;
        Collections.swap(this.array, 0, lastIndex);

        // Delete the last element
        array.remove(lastIndex);

        // Fix the elements that don't follow the min-heap property after deletion
        minHeapify(0, this.array.size());

        // return the first element
        return val;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    @Override
    public String toString() {
        StringBuilder output = new StringBuilder();
        output.append("[");
        int size = this.array.size();
        for (int i = 0; i < size; i++) {
            output.append(this.array.get(i));
            if (i != size - 1)
                output.append(", ");
        }
        output.append("]");
        return output.toString();
    }

    private static void heapSort(Integer[] array) {
        int size = array.length;
        Heap heap = new Heap(array, size);
        for (int i = 0; i < size; i++) {
            array[i] = heap.remove();
        }
    }

    public static void main(String[] args) {
        Integer[] array = {8, 30, 20, 15, 10, 50, 16};
        heapSort(array);
        for(int i : array) {
            System.out.print(i + " ");
        }
    }
}