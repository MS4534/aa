
#include <stdio.h>
int n, W, i, j, p[10], w[10], M[10][10];
int knapsack() 
{
    int i, j;
    for (i = 0; i <= n; i++) 
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                M[i][j] = 0;
            else if (w[i] > j)
                M[i][j] = M[i - 1][j];
            else
                M[i][j] = (M[i - 1][j] > M[i - 1][j - w[i]] + p[i]) ? M[i - 1][j] : M[i - 1][j - w[i]] + p[i];
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
    printf("Optimal solution: %d\n", M[n][W]);
    return M[n][W];
}
int main() 
{
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the max capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the weight of each object:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profit of each object:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int optimal_solution = knapsack();
    return 0;
}


