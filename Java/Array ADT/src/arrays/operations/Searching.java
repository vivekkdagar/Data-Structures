package arrays.operations;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Searching {

    private static int LinearSearch(List<Integer> array, int key) {
        for (int i = 0; i < array.size(); i++)
            if (array.get(i) == key) {
                // Collections.swap(array,i,0);         for optimization
                return i;
            }
        return -1;
    }

    private static int BinarySearch(List<Integer> array, int key) {
        array.sort(Comparator.naturalOrder());
        int low = 0, high = array.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (array.get(mid) == key)
                return mid;
            if (array.get(mid) > key)
                high = mid - 1;
            else {
                low = mid + 1;
            }
        }
        return -1;
    }

    // R for recursive
    private static int BinarySearchR(List<Integer> array, int low, int high, int key) {
        int mid;
        if (low <= high) {
            mid = (low + high) / 2;
            if (array.get(mid) == key)
                return mid;
            else if (array.get(mid) > key)
                return BinarySearchR(array, low, mid - 1, key);
            return BinarySearchR(array, mid + 1, high, key);
        }
        return -1;
    }

    public static void main(String[] args) {
        Integer[] arr = {1,2,3,4,5};
        List<Integer> ls = Arrays.asList(arr);
        int find = LinearSearch(ls, 4);
        System.out.println("Found at: " + find);
    }
}
