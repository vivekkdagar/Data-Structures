// Q: Finding Single (and multiple) Missing Element in an Array

package arrays.student_challenge;

public class Challenge1 {
    private static void find(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] + 1 != array[i + 1])
                System.out.println("Missing element " + (array[i] + 1) + " at index " + (i + 1));
        }
        System.out.println("No missing elements");
    }

    public static void main(String[] args) {
        int[] array = {6,7,8,9,10,11,13,14,16,17};
        find(array);
    }
}
