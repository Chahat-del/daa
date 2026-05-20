#include <stdio.h>
#include <math.h>

int x[10];

int place(int row, int col)
{
    int i;

    for(i = 1; i < row; i++)
    {
        if(x[i] == col ||
           abs(x[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

void nQueens(int row, int n)
{
    int col, i;

    for(col = 1; col <= n; col++)
    {
        if(place(row, col))
        {
            x[row] = col;

            if(row == n)
            {
                printf("\nSolution:\n");

                for(i = 1; i <= n; i++)
                    printf("Queen at row %d column %d\n",
                           i, x[i]);
            }
            else
            {
                nQueens(row + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueens(1, n);

    return 0;
}