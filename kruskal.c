#include <stdio.h>

#define INF 999

int parent[10];

int find(int v)
{
    while(parent[v] != 0)
        v = parent[v];

    return v;
}

int unionSet(int u, int v)
{
    if(u != v)
    {
        parent[v] = u;
        return 1;
    }

    return 0;
}

int main()
{
    int n, i, j;
    int cost[10][10];

    int min, mincost = 0;
    int a, b, u, v;
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

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];

                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(unionSet(u, v))
        {
            printf("%d -> %d  cost = %d\n", a, b, min);

            mincost += min;

            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}