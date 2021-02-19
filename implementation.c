#include "header.h"

int* generate_array(int n)
{
    // srand(time(0));
    // no need to generate different numbers each time as we test with same numbers
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        arr[i] = rand();
    }
    
    return arr;
}

long int selSort(int *a, int n)
{
    long int no_of_comparisons = 0;
    int minpos, temp;
    for (int i = 0; i < n; ++i) {
        minpos = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minpos]) {
                no_of_comparisons++;
                minpos = j;
            }
        }
        temp = a[minpos];
        a[minpos] = a[i];
        a[i] = temp;
    }

    return no_of_comparisons;
}

long int bubbleSort(int arr[], int n)
{
    long int no_of_comparisons = 0;
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                no_of_comparisons++;
            }
        }
    }
    return no_of_comparisons;
}

long int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    long int comparisons = 0;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
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

    return comparisons;
}


long int mergeSort(int arr[], int l, int r)
{
    long int fincount = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        fincount += mergeSort(arr, l, m);
        fincount += mergeSort(arr, m + 1, r);
        
        fincount += merge(arr, l, m, r);
    }
    return fincount;
}

long int* partition(int *a, int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    long int comparisons = 0;

    long int *res = (long int *)malloc(sizeof(long int) * 2);

    while (i <= j) {
        while (i <= high && a[i] <= pivot) {
            ++i;
            comparisons++;
        }
        while (j > low && a[j] >= pivot) {
            --j;
            comparisons++;
        }
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    if (j != low) {
        a[low] = a[j];
        a[j] = pivot;
    }

    res[0] = j;
    res[1] = comparisons;
    return res;
}

long int quickSort(int *a, int low, int high) {
    int j;
    int fincount = 0;
    if (low < high)
    {
        long int *result = partition(a, low, high);
        j = result[0];

        fincount += result[1]; 
        fincount += quickSort(a, low, j - 1);
        fincount += quickSort(a, j + 1, high);
        free(result);
    }
    return fincount;
}
