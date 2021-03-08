#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        arr[arr[i] % size] = arr[arr[i] % size] + size;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= size * 2)
        {
            cout << i << endl;
        }
    }

    return 0;
}