#include <stdio.h>

int parent[10];

int find(int v)
{
    while(parent[v])
        v = parent[v];

    return v;
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

    printf("Enter cost matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nEdges in MST are:\n");

    while(edges < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
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

        if(u != v)
        {
            printf("%d -> %d = %d\n", a, b, min);

            mincost += min;

            parent[v] = u;

            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d", mincost);

    return 0;
}