package arrays.operations;

import java.util.*;

public class RearrangeNegatives {

    // Rearrange all negatives to the right side
    private static void rearrange(List<Integer> array) {
        int size = array.size();
        int i = 0, j = size - 1;
        while (i < j) {

            while (i < size && array.get(i) < 0) i++;
            while (array.get(j) >= 0) j--;

            if (i < j)
                Collections.swap(array, i, j);
        }
    }

    public static void main(String[] args) {
        Integer[] array = {-2, 9, -51, 55, -4, 63, -6};
        List<Integer> arr = Arrays.asList(array);
        rearrange(arr);
        for (int i : arr)
            System.out.print(i + " ");
    }
}
