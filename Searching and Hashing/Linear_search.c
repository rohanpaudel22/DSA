// Program to search a element in a given array by using linear search algorithm

#include<stdio.h>
#define MAX 100
int LinearSearch(int A[], int size, int key);

int main()
{
    int n, a[MAX], key, indexpos;

    printf("Enter the number of data in the array:");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid array size. Please enter a valid size between 1 and %d.", MAX);
        return 1;
    }

    printf("Enter %d number of array elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    indexpos = LinearSearch(a, n, key);

    if (indexpos != -1)
    {
        printf("%d is at index position %d in the given array.\n", key, indexpos);
    }
    else
    {
        printf("%d is not in the given array.\n", key);
    }

    return 0;
}

int LinearSearch(int A[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] == key)
            return i;
    }
    return -1;
}
