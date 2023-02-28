package arrays.operations;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class ReverseArrays {

    // Using auxiliary array
    private static void auxiliary(List<Integer> list) {
        int size = list.size();
        List<Integer> auxi = new ArrayList<>(size);

        // Append elements, starting from back to first element
        for (int i = size - 1; i >= 0; i--) {
            auxi.add(list.get(i));
        }

        // Copy elements back
        for (int i = 0; i < size; i++)
            list.set(i, auxi.get(i));
    }

    // Without using auxiliary array
    private static void reverse(List<Integer> list) {
        int j = list.size() - 1;
        for (int i = 0; i < j; i++) {
            Collections.swap(list, i, j);
            j--;
        }
    }

    public static void main(String[] args) {
        Integer[] array = {-1, -100, 3, 99, 5};
        List<Integer> ls = Arrays.asList(array);
        reverse(ls);
        for (int i : ls)
            System.out.println(i);
    }
}
