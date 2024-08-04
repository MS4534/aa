
#include<stdio.h>
int ne=1,cost[10][10],min,a,b;
void main() 
{
    int i,j,n,u,v,parent[10],mincost=0;
    printf("Enter the no of vertex:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    parent[i]=0;
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(parent[u])
        {
            u=parent[u];
        }
         while(parent[v])
        {
            u=parent[v];
        }
        if(u!=v)
        {
            printf("Edge %d(%d to %d) min cost is %d\n",ne++,u,v,min);
            mincost+=min;
            cost[a][b]=cost[b][a]=999;
        }
    }
    printf("The minimum cost= %d",mincost);
}

