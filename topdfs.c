#include <stdio.h>

int a[10][10], visited[10], stack[10];
int n, top = -1;

void dfs(int v)
{
    int i;

    visited[v] = 1;

    for(i = 0; i < n; i++)
    {
        if(a[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }

    stack[++top] = v;
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
            dfs(i);
    }

    printf("\nTopological Order:\n");

    while(top != -1)
    {
        printf("%d ", stack[top--]);
    }

    return 0;
}