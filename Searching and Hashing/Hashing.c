// Program to search element by using hashing techneques
#include <stdio.h>
#define MAX 100

int createHashTable(int val, int probe, int hash[], int h);
int search(int key, int probe, int hash[], int h);

int main()
{
    int i, n, a[MAX], key;
    int h, indexpos, indexpos1; // for hashtable size
    // int low = 0;

    printf("Enter the number of data in array:");
    scanf("%d", &n);

    printf("Enter %d number of array elements: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // for hashtable
    printf("Enter the size of the hash table:");
    scanf("%d", &h);
    printf("Enter the value to search: ");
    scanf("%d", &key);

    int hash[h];
    for (i = 0; i < h; i++)
    {
        hash[i] = -1;
    }

    int value;
    for (i = 0; i < n; i++)
    {
        value = a[i];
        createHashTable(value, 0, hash, h);
        if (key == a[i])
        {
            indexpos1 = i;
        }
    }

    printf("\nHash Array is : ");
    for (i = 0; i < h; i++)
    {
        printf("%d ", hash[i]);
    }
    printf("\n\nGiven Array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // to search
    int search_key = search(key, 0, hash, h);
    if (search_key != -1)
    {
        indexpos = search_key;
        printf("\n\n%d is at index position %d in the Hash array.", key, indexpos);
        printf("\n\n%d is at index position %d in the Given array.", key, indexpos1);
    }
    else
    {
        printf("\n\n%d is not present in the Hash array.", key);
        printf("\n\n%d is not present in the Given array.", key);
    }

    return 0;
}

int createHashTable(int val, int probe, int hash[], int h)
{
    int temp;
    temp = ((val % h + probe) % h);
    if (hash[temp] == -1)
    {
        hash[temp] = val;
    }
    else if (hash[temp] != -1)
    {
        createHashTable(val, probe + 1, hash, h);
    }
}

int search(int key, int probe, int hash[], int h)
{
    int temp;
    temp = ((key % h + probe) % h);
    if (hash[temp] == key)
    {
        return temp;
    }
    else
    {
        if (probe < h - 1)
        {
            return search(key, probe + 1, hash, h);
        }
        else
            return -1;
    }
}
