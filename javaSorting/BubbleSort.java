import java.util.Arrays;

public class BubbleSort {

    public static void main(String[] args) {
        int[] arr = {4, 7, 2, 8, 3, 2, 1, 9, 6, 5};
        System.out.println(Arrays.toString(arr));
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void bubbleSort(int[] arr){
        for (int i = 0; i < arr.length; i++) {
            boolean isSwapped = false;
            for (int j = 1; j < arr.length - i; j++){
                if (arr[j] < arr[j-1]){
                    swap(arr, j, j-1);
                    isSwapped = true;
                }
            }
            if (isSwapped == false){
                break;
            }
        }
    }

    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
