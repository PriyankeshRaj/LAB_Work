#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *arr, int size)
{
    int current, temp, j;
    for (int i = 0; i < size; i++)
    {
        current = *(arr + i);
        j = i - 1;
        while (j >= 0 && current < *(arr + j))
        {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = current;
    }
    printf("\nSorted\n");
}

int main()
{
    //Menu
    int n;
    int size;
    int *arr;
    while (1)
    {
        printf("\nEnter 0 to enter menu again: ");
        printf("\nEnter 1 to enter array: ");
        printf("\nEnter 2 to sort using INSERTION SORT: ");
        printf("\nEnter 3 to print the array: ");
        printf("\nEnter 4 to exit the program: \nn : ");

        scanf("%d", &n);

        if (n == 0)
        {
            continue;
        }
        if (n == 1)
        {
            printf("\nEnter the size of array to be sorted: ");
            scanf("%d", &size);
            arr = (int *)malloc(size * sizeof(int));
            printf("Enter the elements: ");
            for (int i = 0; i < size; i++)
            {
                scanf("%d", (arr + i));
            }
        }
        if (n == 2)
        {
            double time_cons;
            clock_t start, end;
            start = clock();
            insertion_sort(arr, size);
            end = clock();
            time_cons += (double)(end - start) / CLOCKS_PER_SEC;
            printf("Time consumed: %f \n", time_cons);
        }

        if (n == 3)
        {
            for (int i = 0; i < size; i++)
                printf("%d ", *(arr + i));
            printf("\n");
        }
        if (n == 4)
        {
            return 0;
        }
        else if (n != 1 || n != 2 || n != 0 || n != 3 || n != 4)
        {
            printf("\nPlease Enter required option only.\n");
            continue;
        }
    }
    return 0;
}
