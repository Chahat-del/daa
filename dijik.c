#include <stdio.h>

#define INF 999

void dijkstra(int n, int cost[10][10], int source)
{
    int dist[10], visited[10];
    int i, j, min, next;

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;

    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(dist[j] < min && visited[j] == 0)
            {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0)
            {
                if(min + cost[next][j] < dist[j])
                {
                    dist[j] =
                    min + cost[next][j];
                }
            }
        }
    }

    printf("\nShortest paths from vertex %d:\n",
           source);

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n",
               source, i, dist[i]);
    }
}

int main()
{
    int n, i, j, source;
    int cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(n, cost, source);

    return 0;
}