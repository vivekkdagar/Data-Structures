// Q: Finding Duplicates in a Sorted Array

package arrays.student_challenge;

import java.util.Arrays;

public class Challenge2 {

    private static void find(int[] array) {

        // Sort it if it isn't sorted already
        Arrays.sort(array);

        for(int i = 0; i < array.length-1; i++) {
            if(array[i] == array[i+1]) {
                int j = i+1;
                while(j < array.length && array[j] == array[i]) j++;
                System.out.println(array[i] + " is occurring " + (j-i) + " times");
                i++;
            }
        }
    }

    public static void main(String[] args) {
        int[] array = {3,6,8,8,10,12,12,12,15,15,15,20,20,20,13,13};
        find(array);
    }
}
