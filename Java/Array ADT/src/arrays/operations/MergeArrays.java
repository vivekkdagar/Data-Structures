package arrays.operations;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class MergeArrays {

    private static List<Integer> merge(List<Integer> ar1, List<Integer> ar2) {
        // Sorting
        ar1.sort(Comparator.naturalOrder());
        ar2.sort(Comparator.naturalOrder());

        // Prepping a 3rd array to store the results
        int s1 = ar1.size(), s2 = ar2.size(), i, j;
        List<Integer> ar3 = new ArrayList<Integer>(s1 + s2);

        i = j = 0;

        // Merging
        while (i < s1 && j < s2) {
            if (ar1.get(i) > ar2.get(j)) {
                ar3.add(ar2.get(j));
                j++;
            } else {
                ar3.add(ar1.get(i));
                i++;
            }
        }

        // Copying over remaining elements of array 1 and array 2
        while (i < s1) {
            ar3.add(ar1.get(i));
            i++;
        }

        while (j < s2) {
            ar3.add(ar2.get(j));
            j++;
        }

        return ar3;
    }

    public static void main(String[] args) {
        Integer[] v1 = {3, 8, 16, 20, 25, 91, 87};
        Integer[] v2 = {4, 10, 10, 12, 22, 23};
        List<Integer> merged = merge(Arrays.asList(v1), Arrays.asList(v2));
        for (int i : merged) {
            System.out.print(i + " ");
        }
    }
}
