#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{

    int arr[] = {3, 5, 6, 9, 11, 18, 20, 21, 24, 30};
    clock_t begin, end;
    double timetaken;
    begin = clock();
    int x = 6;
    int result = binarySearch(arr, 0, 9, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
    end = clock();
    timetaken = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime = %f\n", timetaken);
    return 0;
}