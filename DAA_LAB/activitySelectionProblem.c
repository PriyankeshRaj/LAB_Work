#include <stdio.h>
void activitySelectionSort(int **s, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(*(s + 1) + j) > *(*(s + 1) + (j + 1)))
            {
                temp = *(*(s + 1) + (j + 1));
                *(*(s + 1) + (j + 1)) = *(*(s + 1) + j);
                *(*(s + 1) + j) = temp;

                temp = *(*(s + 0) + (j + 1));
                *(*(s + 0) + (j + 1)) = *(*(s + 0) + j);
                *(*(s + 0) + j) = temp;
            }
        }
    }
}

void activitySelection(int n, int s[2][n])
{
    for (int i = 0; i < n; i++)
    {
    }
}

int main()
{
    int n;
    printf("\nEnter the size of the activity: ");
    scanf("%d", &n);
    printf("\nEnter the activity details: ");
    int s[2][n];
    for (int i = 0; i < n; i++)
    {
        printf("Start-Time[%d]: ", i);
        scanf("%d", &s[0][i]);
        printf("Finish-Time[%d]: ", i);
        scanf("%d", &s[1][i]);
    }
    activitySelectionSort(s, n);
    activitySelection(n, s);
    return 0;
}