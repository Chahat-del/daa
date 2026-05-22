#include <stdio.h>

int a[20][20], visited[20], queue[20];
int n;

void bfs(int start)
{
    int front = 0, rear = 0;
    int i;

    queue[rear] = start;
    rear++;

    visited[start] = 1;

    while(front < rear)
    {
        int v = queue[front];
        front++;

        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

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

    printf("\nBFS Traversal:\n");

    bfs(start);

    return 0;
}