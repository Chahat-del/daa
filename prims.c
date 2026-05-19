#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j;
    int cost[10][10];
    int visited[10] = {0};

    int min, mincost = 0;
    int a, b;
    int edges = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d -> %d  cost = %d\n", a, b, min);

        mincost += min;

        visited[b] = 1;

        edges++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}