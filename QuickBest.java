package develhope;
import java.util.ArrayList;
import java.util.Scanner;

public class SplitIntegerListIntoTwoEqualParts {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt the user for input or choose default
        System.out.print("Do you want to input numbers yourself? (yes/no): ");
        String userChoice = scanner.nextLine();

        ArrayList<Integer> numbers = new ArrayList<>();

        if (userChoice.equalsIgnoreCase("yes")) {
            int count;

            // Capture count (even) of elements in the list and validate that it's even
            while (true) {
                System.out.print("Type in the (even) number of elements: ");
                count = scanner.nextInt();
                
                // Verify count is even
                if (count % 2 == 0) {
                    break;  // Break loop if count is even
                } else {
                    System.out.println("The number of elements must be even. Please try again.");
                }
            }

            // Input: elements of the ArrayList
            System.out.println("Please enter the integers one by one (if fewer than " + count + " are entered, remaining will be filled with 0s):");
            for (int i = 0; i < count; i++) {
                if (scanner.hasNextInt()) {
                    numbers.add(scanner.nextInt());
                } else {
                    // Fill remaining elements with 0s
                    numbers.add(0);
                }
            }

            // If user entered fewer elements, fill the remaining with 0
            while (numbers.size() < count) {
                numbers.add(0);
            }

        } else {
            // Default hardcoded list (as in the ArrayListSplitter example)
            numbers.add(1);
            numbers.add(2);
            numbers.add(3);
            numbers.add(4);
            numbers.add(5);
            numbers.add(6);
            numbers.add(7);
            numbers.add(8);

            System.out.println("Using default list: " + numbers);
        }

        // Store input in ArrayList and print the entire list
        System.out.println("You entered: " + numbers);

        // Call the split function
        splitAndPrintList(numbers);

        // Cleanup by closing the scanner
        scanner.close();
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
