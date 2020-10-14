#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int bruteMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int bruteMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int max(int arr[], int s, int n)
{
    int maximum;
    if (s >= n - 2)
    {
        if (arr[s] > arr[s + 1])
            return arr[s];
        else
            return arr[s + 1];
    }
    maximum = max(arr, s + 1, n);
    if (arr[s] > maximum)
        return arr[s];
    else
        return maximum;
}

int min(int arr[], int s, int n)
{
    int minimum;
    if (s >= n - 2)
    {
        if (arr[s] < arr[s + 1])
            return arr[s];
        else
            return arr[s + 1];
    }
    minimum = min(arr, s + 1, n);
    if (arr[s] < minimum)
        return arr[s];
    else
        return minimum;
}

int main()
{
    clock_t begin, end;
    double tt3, timetaken, tt2, tt1;
    int flag = 1;
    int n;
    int count = 0;
    int arr[100000];
    while (flag != 0)
    {
        printf("\n0.Exit\n1.Input rand Data\n2.Print Data\n3.Find Max and Min using DAC\n4.Brute Force algo\n5.Comparison of Time Complexity\n6.Test Case\nInput : ");
        scanf("%d", &flag);
        if (flag == 0)
        {
            exit(0);
        }
        if (flag == 1)
        {
            printf("\nNo of elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n;
            }
        }
        if (flag == 2)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        if (flag == 3)
        {
            begin = clock();
            printf("\nMax= %d", max(arr, 0, n));
            printf("\nMin= %d", min(arr, 0, n));
            end = clock();
            timetaken = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nTime in Divide and Conquer case = %f", timetaken);
        }
        if (flag == 4)
        {
            begin = clock();
            printf("\nMax= %d", bruteMax(arr, n));
            printf("\nMin= %d", bruteMin(arr, n));
            end = clock();
            timetaken = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nTime in Brute Force algo case = %f", timetaken);
        }
        if (flag == 5)
        {
            begin = clock();
            printf("\nMax= %d", max(arr, 0, n));
            printf("\tMin= %d", min(arr, 0, n));
            end = clock();
            tt1 = (double)(end - begin) / CLOCKS_PER_SEC;
            begin = clock();
            printf("\nMax= %d", bruteMax(arr, n));
            printf("\tMin= %d", bruteMin(arr, n));
            end = clock();
            tt2 = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nTime in Divide And Conquer case = \t%f", tt1);
            printf("\nTime in Brute Force algo case = \t%f", tt2);
        }
        if (flag == 6)
        {
            int a[] = {8, 2, 4, 1, 3};
            printf("\nDAC Max= %d", max(a, 0, 5));
            printf("\tMin= %d", min(a, 0, 5));
            printf("\nSimple Max= %d", bruteMax(a, 5));
            printf("\tMin= %d", bruteMin(a, 5));
        }
    }
    return 0;
}
