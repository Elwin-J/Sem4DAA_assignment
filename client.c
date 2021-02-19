#include "header.h"

int main()
{
    int n = 1000;
    int *arr = generate_array(n);
    double cpu_time_used[4];
    long int comps[4];
    
    clock_t start, end;

    start = clock();
    comps[0] = selSort(arr, n);
    end = clock();
    cpu_time_used[0] = ((double) (end - start)) / CLOCKS_PER_SEC;

    arr = generate_array(n);
    start = clock();
    comps[1] = bubbleSort(arr, n);
    end = clock();
    cpu_time_used[1] = ((double) (end - start)) / CLOCKS_PER_SEC;

    arr = generate_array(n);
    start = clock();
    comps[2] = quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used[2] = ((double) (end - start)) / CLOCKS_PER_SEC;

    arr = generate_array(n);
    start = clock();
    comps[3] = mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used[3] = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Selection, Bubble, Quick, Merge\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%lf\t%ld\n", cpu_time_used[i], comps[i]);
    }
    
    free(arr);
    return 0;
}
