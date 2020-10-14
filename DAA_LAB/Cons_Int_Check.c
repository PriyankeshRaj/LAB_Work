#include <stdio.h>
#include <time.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int Cons(int a, int b)
{
    int t = min(a, b);
    while (t > 0)
    {
        if (a % t == 0 && b % t == 0)
            return t;

        t--;
    }
}

int main()
{
    int a, b;
    printf("\nEnter two numbers to get their GCD:(A,B) ");
    scanf("%d,%d", &a, &b);
    double time_taken = 0;
    clock_t begin, end;
    begin = clock();

    int cons = Cons(a, b);

    end = clock();
    time_taken += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%d", cons);
    printf("\nTime Taken = %f", time_taken);
}