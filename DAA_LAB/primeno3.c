#include <stdio.h>
#include <time.h>
#include <math.h>

int prime(int n)
{
    if (n <= 1)
        return -1;
    if (n == 2)
        return 1;
    if (n > 2 && n % 2 == 0)
        return -1;

    int m = (int)(sqrt(n));
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return -1;
        }
    }
    return 1;
}

int main()
{
    printf("Enter a number");
    int n = 0;
    int flag = 0;
    scanf("%d", &n);
    clock_t t, t0;
    t = clock();
    if (prime(n) == 1)
        printf("Prime \n");
    else
        printf("Not Prime \n");
    t0 = clock() - t;
    double time_taken0 = ((double)t0) / CLOCKS_PER_SEC;
    printf("Time taken %f seconds \n", time_taken0);
    return 0;
}
