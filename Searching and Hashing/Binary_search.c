// Program to search a element in a given array by using binary search algorithm

#include <stdio.h>
#define MAX 100
void BubbleSort(int a[], int n);
int BinarySearch(int A[], int low, int high, int key);

int main()
{
    int i, n, a[MAX], key;
    int indexpos;

    printf("Enter the number of data in the array: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("Invalid array size. Please enter a valid size between 1 and %d.", MAX);
        return 1;
    }

    printf("Enter %d numbers for the array (preferred sorted order):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    BubbleSort(a, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    indexpos = BinarySearch(a, 0, n - 1, key);

    if (indexpos != -1)
    {
        printf("\n%d is at index position %d in the final sorted array.\n", key, indexpos);
    }
    else
    {
        printf("%d is not in the given array.\n", key);
    }

    return 0;
}

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int BinarySearch(int A[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] > key)
        {
            return BinarySearch(A, low, mid - 1, key);
        }
        else
        {
            return BinarySearch(A, mid + 1, high, key);
        }
    }
    return -1;
}
