#include <stdio.h>

int set[10], subset[10];
int n, sum;

void subsetSum(int index, int k, int currentSum)
{
    int i;

    if(currentSum == sum)
    {
        printf("{ ");

        for(i = 0; i < k; i++)
            printf("%d ", subset[i]);

        printf("}\n");

        return;
    }

    if(currentSum > sum || index >= n)
        return;

    subset[k] = set[index];

    subsetSum(index + 1,
              k + 1,
              currentSum + set[index]);

    subsetSum(index + 1,
              k,
              currentSum);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter required sum: ");
    scanf("%d", &sum);

    printf("\nPossible subsets are:\n");

    subsetSum(0, 0, 0);

    return 0;
}