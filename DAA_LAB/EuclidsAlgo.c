#include <stdio.h>
#include <time.h>

int Euclid(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int r = a % b;
    return Euclid(b, r);
}

int main()
{
    int a, b;
    printf("\nEnter two numbers to get their GCD:(A,B) ");
    scanf("%d,%d", &a, &b);
    double time_taken = 0;
    clock_t begin, end;
    begin = clock();

    int euc = Euclid(a, b);

    end = clock();
    time_taken += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%d", euc);
    printf("\nTime Taken = %f", time_taken);
}