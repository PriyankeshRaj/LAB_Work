#include <stdio.h>
#include <time.h>

void primeno(int n)
{
    clock_t t, t0;
    t = clock();
    if (n == 1)
    {
        printf("\nNot prime");
    }
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                printf("\nNot Prime No");
                n = 0;
                break;
            }
        }
        if (n != 0)
        {
            printf("\nPrime");
        }
    }
    t0 = clock() - t;
    double time_taken = ((double)t0) / CLOCKS_PER_SEC;
    printf("\nTime Taken = %f sec", time_taken);
}

int main()
{
    int n = 1, a;
    while (n == 1)
    {
        printf("\nEnter 0 to close or 1 to continue: ");
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        printf("\nEnter No to check for Prime: ");
        scanf("%d", &a);
        //check prime
        primeno(a);
    }
}