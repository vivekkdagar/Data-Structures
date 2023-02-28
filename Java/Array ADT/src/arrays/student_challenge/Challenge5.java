// Q: Find a pair of elements with sum K in a sorted and unsorted array

package arrays.student_challenge;

import java.util.Arrays;

public class Challenge5 {

    // For sorted array
    private static void sorted(int[] array, int k) {

        // Sort it if it isn't sorted already
        Arrays.sort(array);

        int i = 0, j = array.length - 1;
        while (i < j) {
            if (array[i] + array[j] == k) {
                System.out.println("Pair found: [" + array[i] + ", " + array[j] + "]");
                i++;
                j--;
            } else if (array[i] + array[j] < k)
                i++;
            else
                j--;
        }
    }

    // For unsorted array
    private static void unsorted(int[] array, int k) {
        int size = array.length;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++)
                if (array[i] + array[j] == k)
                    System.out.println("Pair found: [" + array[i] + ", " + array[j] + "]");
        }
    }

    // Method 2 for unsorted array
    private static void unsorted2(int[] array, int k) {
        int[] hashtable = new int[Arrays.stream(array).max().getAsInt() + 1];
        Arrays.fill(hashtable, 0);

        for (int t : array) {
            if ((k - t) >= 0 && hashtable[k - t] != 0)
                System.out.println("Pair found: [" + t + ", " + (k - t) + "]");
            hashtable[t]++;
        }
    }

    public static void main(String[] args) {
        int[] array = {10,7,8,9,1,2,4,3,6,5};
        unsorted2(array, 10);
    }
}
