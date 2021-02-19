#include "header.h"

int main()
{
    FILE *compare, *timeTaken;
    compare = fopen("SizeVsNumberOfComparisions.txt", "w");
    timeTaken = fopen("SizeVsNumberOfExecutionTime.txt", "w");

    if(compare == NULL || timeTaken == NULL) 
    {
        printf("Error!");
        exit(1);
    }

    //for(int n=100000; n<1000000;n+=50000){
    for(int n=1000; n<3000;n+=1000){

        int *arr = generate_array(n);
        double cpu_time_used[4];
        long int comps[4];

        clock_t start, end;

        start = clock();
        comps[0] = selSort(arr, n);
        end = clock();
        cpu_time_used[0] = ((double) (end - start)) / CLOCKS_PER_SEC;
        free(arr);

        arr = generate_array(n);
        start = clock();
        comps[1] = bubbleSort(arr, n);
        end = clock();
        cpu_time_used[1] = ((double) (end - start)) / CLOCKS_PER_SEC;
        free(arr);

        arr = generate_array(n);
        start = clock();
        comps[2] = quickSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used[2] = ((double) (end - start)) / CLOCKS_PER_SEC;
        free(arr);

        arr = generate_array(n);
        start = clock();
        comps[3] = mergeSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used[3] = ((double) (end - start)) / CLOCKS_PER_SEC;
        free(arr);

        fprintf(compare,"\nn=%d \n",n);
        fprintf(timeTaken,"\nn=%d \n",n);
        // printf("Selection, Bubble, Quick, Merge\n");
        printf("Sorting in progress....\n");
        for (int i = 0; i < 4; i++)
        {
            //printf("%lf\t%ld\n", cpu_time_used[i], comps[i]);

            fprintf(compare,"%ld \n", comps[i]);
            fprintf(timeTaken,"%lf \n",cpu_time_used[i]);
        }
    }
    fclose(compare);
    fclose(timeTaken);
    printf("Sorting done!!\n");

    return 0;
}