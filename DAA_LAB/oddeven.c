#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("Enter Size of array: \n");
    scanf("%d", &n);
    int a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (50 - 0) + 0;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int e = 0, o = n - 1; e < o; e++, o--)
    {
        while (a[o] % 2 != 0)
            o--;
        while (a[e] % 2 == 0)
            e++;
        if (e >= o)
            break;
        swap(&a[e], &a[o]);
    }
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
