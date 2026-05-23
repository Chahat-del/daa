#include <stdio.h>

int a[10][10], indegree[10];
int queue[10];
int n;

int main()
{
    int i, j;
    int front = 0, rear = -1;
    int count = 0;

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
        indegree[i] = 0;

        for(j = 0; j < n; j++)
        {
            indegree[i] += a[j][i];
        }
    }

    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }

    printf("\nTopological Order:\n");

    while(front <= rear)
    {
        int v = queue[front++];

        printf("%d ", v);

        count++;

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                {
                    queue[++rear] = i;
                }
            }
        }
    }

    if(count != n)
    {
        printf("\nCycle exists");
    }

    return 0;
}