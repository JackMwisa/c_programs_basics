public class JumpSearch {
    public static int jumpSearch(int[] arr, int x) {
        int n = arr.length;
        
        // Step size
        int step = (int)Math.floor(Math.sqrt(n));
        int prev = 0;

        // Jumping through the blocks
        while (arr[Math.min(step, n)-1] < x) {
            prev = step;
            step += (int)Math.floor(Math.sqrt(n));
            if (prev >= n) {
                return -1;
            }
        }

        // Performing linear search within the block
        while (arr[prev] < x) {
            prev++;
            if (prev == Math.min(step, n)) {
                return -1;
            }
        }

        // Return index if element is found
        if (arr[prev] == x) {
            return prev;
        }

        return -1;
    }

    public static void main(String[] args) {
        int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
        int x = 55;

        // Execute jump search
        int index = jumpSearch(arr, x);

        // Print the index
        System.out.println("\nNumber " + x + " is at index " + index);
    }
}

