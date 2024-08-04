#include<stdio.h>
int n, a[10][10], indegree[10];
void find_indegree() 
{
    int i, j, sum;
    for(j = 1; j <= n; j++) 
    {
        sum = 0;
        for(i = 1; i <= n; i++) 
        {
            sum = sum + a[i][j];
        }
        indegree[j] = sum;
    }
}
void topo() 
{
    int i, u, v, k = 0, top = -1, t[10];
    int s[10];
    find_indegree();
     // Initialize stack 's' with vertices having 0 in-degree
    for(i = 1; i <= n; i++) 
    {
        if(indegree[i] == 0) 
        {
            s[++top] = i;
        }
    }
     while(top != -1) 
     {
        u = s[top--];
        printf("%d\t", u);
        t[k++] = u;
        // Reduce in-degree of all neighbors of u by 1
        for(v = 1; v <= n; v++) 
        {
            if(a[u][v] == 1)
            {
                indegree[v]--;
                if(indegree[v] == 0) 
                {
                    s[++top] = v; // Push v to stack if its in-degree becomes 0
                }
            }
        }
    }
    printf("\nResultant topological order is: ");
    for(i = 0; i < k; i++)
        printf("%d ", t[i]);
}

int main() 
{
    int i, j;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    printf("Enter elements of the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }
    topo();
   return 0;
}
