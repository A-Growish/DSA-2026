/*WACP to take input in an array 10 unordered number and
apply QuickSort to order the array in ascending order.
input values:- [8,2,10,6,5,12,18,9,4,11]
*/

#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10] = {8, 2, 10, 6, 5, 12, 18, 9, 4, 11};
    int n = 10;

    printf("Original Array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\n\nSorted Array (Ascending Order):\n");
    printArray(arr, n);

    return 0;
}
