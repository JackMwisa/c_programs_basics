package develhope;
import java.util.ArrayList;

public class ArrayListSplitter {
    public static void main(String[] args) {
        // Create an ArrayList of integers with an even number of elements
        ArrayList<Integer> integerList = new ArrayList<>();
        integerList.add(1);
         integerList.add(2);
        integerList.add(3);
        integerList.add(4);
        integerList.add(5);
        integerList.add(6);
        integerList.add(7);
        integerList.add(8);

        // Split the list into two halves and print both halves
        splitAndPrintList(integerList);
    }

    public static void splitAndPrintList(ArrayList<Integer> list) {
        if (list == null || list.size() % 2 != 0) {
            System.out.println("Error: The list must have an even number of elements.");
            return;
        }

        int midpoint = list.size() / 2;

        // Create the two halves
        ArrayList<Integer> firstHalf = new ArrayList<>(list.subList(0, midpoint));
        ArrayList<Integer> secondHalf = new ArrayList<>(list.subList(midpoint, list.size()));

        // Print both halves
        System.out.println("First half: " + firstHalf);
        System.out.println("Second half: " + secondHalf);
    }
}
