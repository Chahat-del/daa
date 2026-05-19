#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int lcs(char X[], char Y[], int m, int n)
{
    if(m == 0 || n == 0)
        return 0;

    if(X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);

    else
        return max(lcs(X, Y, m, n-1),
                   lcs(X, Y, m-1, n));
}

int main()
{
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("\nLength of first string = %d", m);

    printf("\nLength of second string = %d", n);

    printf("\nLength of LCS = %d",
           lcs(X, Y, m, n));

    return 0;
}