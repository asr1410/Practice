#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first = 1, second = 2, sum = 2, temp;
    while (second < 4000000)
    {
        temp = first + second;
        first = second;
        second = temp;
        if (temp % 2 == 0)
        {
            sum = sum + temp;
        }
    }
    cout << sum;
    return 0;
}