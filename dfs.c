#include <stdio.h>

int a[20][20], visited[20], n;

void dfs(int v)
{
    int i;

    visited[v] = 1;

    printf("%d ", v);

    for(i = 0; i < n; i++)
    {
        if(a[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start, count = 0;

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
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal:\n");

    dfs(start);

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 1)
            count++;
    }

    if(count == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}