#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Exch(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[], int low, int high)
{
    int i, j, key;

    if(low >= high)
        return;

    key = low;
    i = low + 1;
    j = high;

    while(i <= j)
    {
        while(i <= high && a[i] <= a[key])
            i++;

        while(a[j] > a[key])
            j--;

        if(i < j)
            Exch(&a[i], &a[j]);
    }

    Exch(&a[j], &a[key]);

    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

int main()
{
    int n, a[5000], k;
    clock_t st, et;
    double ts;

    printf("Enter the number of elements\n");
    scanf("%d", &n);

    printf("The elements to array using Random Generator\n");

    for(k = 0; k < n; k++)
    {
        a[k] = rand() % 1000;
    }

    st = clock();

    QuickSort(a, 0, n - 1);

    et = clock();

    ts = (double)(et - st) / CLOCKS_PER_SEC;

    printf("The time taken by the elements after sorting %lf", ts);

    return 0;
}