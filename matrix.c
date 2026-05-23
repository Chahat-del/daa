#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int p[], int n)
{
    int m[10][10];
    int i, j, k, L, q;

    for(i = 1; i < n; i++)
        m[i][i] = 0;

    for(L = 2; L < n; L++)
    {
        for(i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;

            m[i][j] = INT_MAX;

            for(k = i; k < j; k++)
            {
                q = m[i][k] +
                    m[k+1][j] +
                    p[i-1] * p[k] * p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n-1];
}

int main()
{
    int n, i;
    int p[10];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array:\n");

    for(i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("\nMinimum number of multiplications = %d",
           MatrixChainOrder(p, n + 1));

    return 0;
}