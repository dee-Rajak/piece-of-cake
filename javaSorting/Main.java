import java.util.Arrays;

public class Main{
    public static void main(String[] args) {
        int[] arr = {4, 7, 2, 8, 3, 2, 1, 9, 6, 5};
        System.out.println(Arrays.toString(arr));
        // SelectionSort.selectionSort(arr);
        BubbleSort.bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}