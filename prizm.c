#include<stdio.h>
int a,b,u,n,v,i,j,ne;
int visited[10]={0},min,mincost=0,cost[10][10];
void main()
{
    printf("Enter the no of vertex:");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    visited[1]=1;
    printf("\n");
    for(ne=1;ne<n;ne++)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0&&visited[j]==0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0||visited[v]==0)
        {
            printf("Edge %d:(%d to %d)min cost is %d\n",ne,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Min cost= %d",mincost);
}

