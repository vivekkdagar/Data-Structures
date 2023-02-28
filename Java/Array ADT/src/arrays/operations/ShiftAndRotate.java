package arrays.operations;

import java.util.Arrays;
import java.util.List;

public class ShiftAndRotate {

    // Left shift: shift all elements to the left by one place
    private static void lshift(List<Integer> list) {
        int size = list.size();
        for (int i = 0; i < size; i++)
            list.set(i, list.get(i + 1));
        list.set(size - 1, 0);
    }

    // Left rotate: rotate all elements to the left by one place
    private static void lRotate(List<Integer> list) {
        int size = list.size(), front = list.get(0);
        for (int i = 0; i < size; i++)
            list.set(i, list.get(i + 1));
        list.set(size - 1, front);
    }

    // Right shift: shift all elements to the right by one place
    private static void rshift(List<Integer> list) {
        for (int t = list.size() - 1; t > 0; t--)
            list.set(t, list.get(t - 1));
        list.set(0, 0);
    }

    // Right rotate: rotate all elements to the right by one place
    private static void rRotate(List<Integer> list) {
        int size = list.size();
        int last = list.get(size - 1);
        for (int t = size - 1; t > 0; t--)
            list.set(t, list.get(t - 1));
        list.set(0, last);
    }

    public static void main(String[] args) {
        Integer[] list = {-1,-100,3,99};
        List<Integer> ls = Arrays.asList(list);
        rRotate(ls);
        rRotate(ls);
        for(int i : ls)
            System.out.print(i + " ");
    }
}
