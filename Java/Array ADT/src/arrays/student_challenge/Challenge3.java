// Q: Find missing element in an array using hashing, similarly find duplicates in an array using hashing

package arrays.student_challenge;

import java.util.Arrays;

public class Challenge3 {

    private static int[] prepareHashTable(int[] array) {
        int max = Arrays.stream(array).max().getAsInt();

        // Prepare the hashtable
        int[] hashTable = new int[max + 1];
        Arrays.fill(hashTable, 0);

        // Fill the hashtable
        for (int i : array)
            hashTable[i]++;

        return hashTable;
    }
    private static void findMissing(int[] array) {
        int[] hashTable = prepareHashTable(array);

        // Find min and max of array
        int min = Arrays.stream(array).min().getAsInt();
        int max = Arrays.stream(array).max().getAsInt();

        // Traverse the hash table
        for (int i = min; i <= max; i++)
            if (hashTable[i] == 0)
                System.out.println(i + " is missing");
    }

    private static void findDuplicates(int[] array) {
        int[] hashTable = prepareHashTable(array);

        for(int i = 0; i < hashTable.length; i++)
            if(hashTable[i] > 1)
                System.out.println(i + " is appearing " + hashTable[i] + " times");
    }

    public static void main(String[] args) {
        int[] array = {3,7,4,9,9,12,6,11,10,10,11,11,11,11};
        findDuplicates(array);
    }
}
