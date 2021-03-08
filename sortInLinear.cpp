#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 1, 0, 2, 1, 0, 2, 1, 0};
    int mid = 0, low = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        default:
            break;
        }
    }
    return 0;
}