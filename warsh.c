#include<stdio.h>
void main()
{
    int i, j, k, cost[10][10], n;
    printf("Enter the no of vertices:");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Edge with cost\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Edge %d to %d cost= %d\n", i, j, cost[i][j]);
        }
    }
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    printf("Edge with shortest path\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Edge %d to %d cost=%d\n", i, j, cost[i][j]);
        }
    }
}


