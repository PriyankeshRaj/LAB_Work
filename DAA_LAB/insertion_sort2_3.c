#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertsort(int arr[], int n)
{
    int a, b, key;
    for (a = 1; a < n; a++)
    {
        key = arr[a];
        b = a - 1;
        while (b >= 0 && arr[b] > key)
        {
            arr[b + 1] = arr[b];
            b = b - 1;
        }
        arr[b + 1] = key;
    }
}

void insertsortreverse(int arr[], int n)
{
    int a, b, key, temp;
    for (a = 1; a < n; a++)
    {
        b = a;
        key = arr[b - 1];
        while (b > 0 && arr[b] > key)
        {
            temp = arr[b];
            arr[b] = arr[b - 1];
            arr[b - 1] = temp;
            b = b - 1;
        }
    }
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
        printf("0.Exit\n1.Input rand Data\n2.Print Data\n3.Sort Asending\n4.Sort Deasending\n5.Average Time Complexity\n6.Best Case Time Compleity\n7.Worst Case Time\n8.Tabular Display\nInput : ");
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("No of elements: ");
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
            insertsort(arr, n);
        }
        if (flag == 4)
        {
            insertsortreverse(arr, n);
        }
        if (flag == 5)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n;
            }
            begin = clock();
            insertsort(arr, n);
            end = clock();
            timetaken = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time in asending random case = %f\n", timetaken);
        }
        if (flag == 6)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n;
            }
            insertsort(arr, n);
            begin = clock();
            insertsort(arr, n);
            end = clock();
            timetaken = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time in asending sorted case = %f\n", timetaken);
        }
        if (flag == 7)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n;
            }
            insertsort(arr, n);
            begin = clock();
            insertsortreverse(arr, n);
            end = clock();
            timetaken = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time in desending sorted Asending case = %f\n", timetaken);
        }
        if (flag == 8)
        {

            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n;
            }
            if (count == 0)
            {
                printf("Sr.no.\t\t Number \t Time(Average) \t\t Time(Best) \t\t Time(Worst) \n");
            }
            count += 1;
            begin = clock();
            insertsort(arr, n);
            end = clock();
            tt1 = (double)(end - begin) / CLOCKS_PER_SEC;

            begin = clock();
            insertsort(arr, n);
            end = clock();
            tt2 = (double)(end - begin) / CLOCKS_PER_SEC;

            begin = clock();
            insertsortreverse(arr, n);
            end = clock();
            tt3 = (double)(end - begin) / CLOCKS_PER_SEC;

            printf(" %d\t\t %d\t\t %f\t\t %f\t\t %f\n", count, n, tt1, tt2, tt3);
        }
    }
}