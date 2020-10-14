#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void mergeReverse(int left[], int n1, int right[], int n2, int arr[], int n)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] >= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

int sort(int arr[], int n)
{
    // Base condition
    if (n < 2)
        return -1;
    //Divide the array
    int middle = n / 2;
    int left[middle];
    for (int i = 0; i < middle; i++)
        left[i] = arr[i];
    int right[n - middle];
    for (int i = middle; i < n; i++)
        right[i - middle] = arr[i];

    //sort the divided array
    sort(left, middle);
    sort(right, n - middle);
    //merge the arrays
    mergeReverse(left, middle, right, n - middle, arr, n);
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void search(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i++)
        heapify(arr, n, i);
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
        printf("0.Exit\n1.Input rand Data\n2.Print Data\n3.Sort Ascending\n4.Sort Descending\n5.Average Time Complexity\n6.Best Case Time Complexity\n7.Worst Case Time Complexity\n8.Tabular Display\n9.Test Case\n10.Largest Element:\n11.Replace Value at a node with new value:\n12.Insert new element:\n13.Delete an element:\nInput : ");
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
            heapsort(arr, n);
        }
        if (flag == 4)
        {
            sort(arr, n);
        }
        if (flag == 5)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n;
            }
            begin = clock();
            heapsort(arr, n);
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
            heapsort(arr, n);
            begin = clock();
            heapsort(arr, n);
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
            heapsort(arr, n);
            begin = clock();
            sort(arr, n);
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
            heapsort(arr, n);
            end = clock();
            tt1 = (double)(end - begin) / CLOCKS_PER_SEC;

            begin = clock();
            heapsort(arr, n);
            end = clock();
            tt2 = (double)(end - begin) / CLOCKS_PER_SEC;

            begin = clock();
            sort(arr, n);
            end = clock();
            tt3 = (double)(end - begin) / CLOCKS_PER_SEC;

            printf(" %d\t\t %d\t\t %f\t\t %f\t\t %f\n", count, n, tt1, tt2, tt3);
        }
        if (flag == 9)
        {
            int a[] = {8, 2, 4, 1, 3};
            heapsort(a, 5);
            printf("\nSorted: ");
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\nLargest element is :%d", a[4]);
            printf("\nReversed: ");
            sort(a, 5);
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
        if (flag == 10)
        {
            heapsort(arr, n);
            printf("\nLargest Element is : %d\n", arr[n - 1]);
        }
        if (flag == 11)
        {
            int pos, new;
            printf("\nEnter the index of the value to be replaced, the new value: ");
            scanf("%d %d", &pos, &new);
            if (pos < n)
            {
                arr[pos] = new;
                heapsort(arr, n);
            }
            else
            {
                printf("Enter Valid index:\n");
            }
        }
        if (flag == 12)
        {
            int new_arr[n + 1];
            for (int i = 0; i < n; i++)
            {
                new_arr[i] = arr[i];
            }
            n = n + 1;
            printf("\nEnter the new value to be inserted: ");
            scanf("%d", &arr[n - 1]);
            heapify(arr, n, n - 1);
        }
        if (flag == 13)
        {
            printf("\nEnter value to be deleted: ");
            int pos, deletenode;
            scanf("%d", &pos);
            deletenode = arr[pos];
            arr[pos] = arr[n - 1];
            n--;
            heapify(arr, n, pos);
        }
    }
}