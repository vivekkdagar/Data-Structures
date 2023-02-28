package arrays.student_challenge;

public class Challenge4 {

    private static void find(int[] array) {
        if(array.length == 0)
            return;

        int min, max;
        min = max = array[0];

        for(int i = 1; i < array.length; i++) {
            if(max < array[i])
                max = array[i];
            else if(min > array[i])
                min = array[i];
        }

        System.out.println("Minimum element is " + min);
        System.out.println("Maximum element is " + max);
    }

    public static void main(String[] args) {
        int[] array = {5, 8, 3, 9, 10, 16, 22, 1, 2, -2, 999};
        find(array);
    }
}
