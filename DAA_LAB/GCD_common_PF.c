#include <stdio.h>
#include <time.h>
#define MAXSIZE 1024
typedef struct
{
    int size;
    int factors[MAXSIZE + 1];
    int exponents[MAXSIZE + 1];

} FACTORIZATION;

void findfactors(int x, FACTORIZATION *factorization)
{

    int i, j, k = 1, c;
    factorization->factors[0] = 1;
    factorization->exponents[0] = 1;

    for (i = 2; i <= x; i++)
    {
        c = 0;
        while (x % i == 0)
        {
            x /= i;
            c++;
        }
        if (c > 0)
        {
            factorization->factors[k] = i;
            factorization->exponents[k] = c;
            k++;
        }
    }
    factorization->size = k - 1;
}

void displayFactors(int x, FACTORIZATION fact)
{
    printf("\nPrime Factos of %d are: ", x);
    for (int i = 0; i <= fact.size; i++)
    {
        printf("%d^%d ", fact.factors[i], fact.exponents[i]);
        if (i < fact.size)
            printf(" * ");
        else
        {
            printf("\n");
        }
    }
}

int CPF(int a, int b)
{
    int i = 0, j = 0, x = 1, min, count;
    FACTORIZATION factorization_a;
    FACTORIZATION factorization_b;
    findfactors(a, &factorization_a);
    displayFactors(a, factorization_a);
    findfactors(b, &factorization_b);
    displayFactors(b, factorization_b);
    while (i <= factorization_a.size && j <= factorization_b.size)
    {
        if (factorization_a.factors[i] < factorization_b.factors[j])
            i++;
        if (factorization_a.factors[i] > factorization_b.factors[j])
            j++;
        if (factorization_a.factors[i] == factorization_b.factors[j])
        {
            min = factorization_a.exponents[i] <= factorization_b.exponents[j] ? factorization_a.exponents[i] : factorization_b.exponents[j];
            count = 0;
            while (count < min)
            {
                x *= factorization_a.factors[i];
                count++;
            }
            i++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return x;
}

int main()
{
    int a, b;
    printf("\nEnter two numbers to get their GCD:(A,B) ");
    scanf("%d,%d", &a, &b);
    double time_taken = 0;
    clock_t begin, end;
    begin = clock();

    int cpf = CPF(a, b);

    end = clock();
    time_taken += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nCommon Prime Factor of (%d,%d) = %d", a, b, cpf);
    printf("\nTime Taken = %f", time_taken);
}