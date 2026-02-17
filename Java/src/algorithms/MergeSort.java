package algorithms;

import java.util.Arrays;

public class MergeSort {
    int [] arr;
    int low, high;
    MergeSort(int... elements) {
        arr = elements;
        low = 0;
        high = elements.length - 1;
        mergeSort(low, high);
    }
    private void mergeSort(int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(low, mid);
            mergeSort(mid+1, high);
            merge(low, mid, high);
        }
    }

    private void merge(int low, int mid, int high) {
        int h = low, i = 0, j = mid+1;
        int [] b = new int[high-low+1];

        while (h <= mid && j <= high) {
            if (arr[h] <= arr[j]){
                b[i++] = arr[h++];
            } else {
                b[i++] = arr[j++];
            }
        }

        if (h > mid) {
            for (int k=j; k<=high; k++) {
                b[i++] = arr[k];
            }
        } else {
            for (int k=h; k<=mid; k++) {
                b[i++] = arr[k];
            }
        }

        for (int value : b) arr[low++] = value;
    }

    public String toString() {
        return Arrays.toString(arr);
    }

    public static void main(String[] args) {
        // test
        int[] array = {310, 285, 179, 652, 351, 423, 861, 254, 450, 520};

        System.out.println(new MergeSort(array));
        // TODO: Implement without object creation
    }
}


