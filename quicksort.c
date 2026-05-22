#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[low];

    i = low + 1;
    j = high;

    while(i <= j)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    int j;

    if(low < high)
    {
        j = partition(a, low, high);

        quicksort(a, low, j - 1);

        quicksort(a, j + 1, high);
    }
}

int main()
{
    int n, a[10000], i;

    clock_t start, end;

    double cpu_time;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    start = clock();

    quicksort(a, 0, n - 1);

    end = clock();

    cpu_time =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted elements are:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nExecution time = %f seconds\n",
           cpu_time);

    return 0;
}