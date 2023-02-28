package arrays.operations;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Set {

    private final List<Integer> array;

    public Set(List<Integer> array) {
        this.array = array;
    }

    // A-B = those elements of A which are not in B
    private List<Integer> difference(List<Integer> src) {
        List<Integer> result = new ArrayList<>();

        for (int i : this.array) {
            if (!src.contains(i)) {
                result.add(i);
            }
        }
        return result;
    }

    // Common elements of both sets
    private List<Integer> intersection(List<Integer> src) {
        List<Integer> result = new ArrayList<>();
        for (int i : this.array) {
            if (src.contains(i))
                result.add(i);
        }
        return result;
    }

    // All elements from both sides
    private List<Integer> union(List<Integer> src) {
        List<Integer> result = new ArrayList<>(this.array);
        for (int i : src) {
            if (!this.array.contains(i))
                result.add(i);
        }
        return result;
    }

    public static void main(String[] args) {
        Integer[] ar1 = {1, 2, 3, 4};
        Integer[] ar2 = {3, 4, 5, 6};
        List<Integer> ls = Arrays.asList(ar2);
        Set s1 = new Set(Arrays.asList(ar1));

        List<Integer> diff = s1.difference(ls);
        System.out.print("Difference: ");
        for (int i : diff)
            System.out.print(i + " ");
        System.out.println();

        List<Integer> intersect = s1.intersection(ls);
        System.out.print("Intersection: ");
        for(int i : intersect)
            System.out.print(i + " ");
        System.out.println();

        List<Integer> union = s1.union(ls);
        System.out.print("Union: ");
        for(int i : union)
            System.out.print(i + " ");
        System.out.println();
    }
}
