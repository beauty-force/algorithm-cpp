/**
 *  \addtogroup sorting Sorting Algorithms
 *  @file{
 *  \file
 *  \breif [Merege Sort Algorithm
 *  (MEREGE SORT)](https://en.wikipedia.org/wiki/Merge_sort) implementation
 *
 *  \author [Ayaan Khan] (http://github.com/ayaankhan98)
 *
 *  Merge Sort is an efficient, general purpose, comparison
 *  based sorting algorithm.
 *  Merge Sort is a divide and conquer algorithm
 *  
 */
#include <iostream>

/**
 *
 * The merge() function is used for merging two halves. 
 * The merge(arr, l, m, r) is key process that assumes that 
 * arr[l..m] and arr[m+1..r] are sorted and merges the two 
 * sorted sub-arrays into one.
 *
 * @param arr[] is the array with two halves one is arr[l...m] and
 * other is arr[m+1...l]
 * @param l is the left index of first half array
 * @param m is the end index of right index of first half array
 * 
 * (The second array starts form m+1 and goes till l)
 * 
 * @param l is the end index of right index of second half array
 */
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1], *R = new int[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

/**
 * Merge sort is a divide and conquer algorithm, it divides the
 * input array into two halves and calls itself for the two halves
 * and then calls merge() to merge the two halves
 *
 * @param arr[] the array which is to be sorted
 * @param l define the left index of array
 * @param r defines the right index of array
 *
 */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * A simple utility function used to print the array after
 * sorting
 */
void show(int arr[], int size) {
    for (int i = 0; i < size; i++)  std::cout << arr[i] << " ";
    std::cout << "\n";
}

/** Main function */
int main() {
    int size;
    std::cout << "Enter the number of elements : ";
    std::cin >> size;
    int *arr = new int[size];
    std::cout << "Enter the unsorted elements : ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, size-1);
    std::cout << "Sorted array : ";
    show(arr, size-1);
    delete[] arr;
    return 0;
}
/** @} */
