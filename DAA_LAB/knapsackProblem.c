#include <stdio.h>

float knapsack(int W, int n, int O[2][n])
{
    int used[n];
    float TotalProfit = 0;
    for (int i = 0; i < n; i++)
        used[i] = 0;
    int max;
    float ratio, ratioMax;
    while (W > 0)
    {
        max = -1;
        for (int i = 0; i < n; i++)
        {
            ratio = (float)O[0][i] / O[1][i];
            if (used[i] == 0 && (max == -1 || ratio > ratioMax))
            {
                max = i;
                ratioMax = (float)O[0][max] / O[1][max];
            }
        }
        used[max] = 1;
        W -= O[1][max];
        if (W >= 0)
            TotalProfit += O[0][max];
        else
            TotalProfit += (1 + ((float)W / O[1][max])) * O[0][max];
    }
    return TotalProfit;
}
int main()
{
    int n, W;
    printf("Enter the no of objects: ");
    scanf("%d", &n);
    int O[2][n];
    // float PWratio[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nProfit[%d]: ", i + 1);
        scanf("%d", &O[0][i]);
        printf("\tWeight[%d]: ", i + 1);
        scanf("%d", &O[1][i]);
        //Profit/Weight
        // PWratio[i] = (float)(O[0][i] / O[1][i]);
    }
    printf("\nKnapsack Capacity: ");
    scanf("%d", &W);
    printf("\nMaximum Possible Value: %f", knapsack(W, n, O));
}