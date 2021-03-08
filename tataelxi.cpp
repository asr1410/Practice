#include <bits/stdc++.h>
using namespace std;
void switchchanges(int n, int q, int *switches, int *queries)
{
    int temp, On, oldbutton, button, count = 0;
    for (int i = 0; i < q; i++)
    {
        On = 0;
        temp = queries[i] - 1;
        if (switches[temp] == 0)
        {
            switches[temp] = 1;
        }
        else
        {
            switches[temp] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (switches[i] == 1)
            {
                On++;
            }
        }
        if (On > n / 2)
        {
            button = 1;
        }
        else
        {
            button = 0;
        }
        cout << button << endl;
        if (i > 0)
        {
            if (button != oldbutton)
            {
                count++;
            }
        }
        oldbutton = button;
    }
    cout << count;
}
int main()
{
    int n;
    int q;
    cin >> n;
    int switches[n];
    for (int i = 0; i < n; i++)
    {
        cin >> switches[i];
    }
    cin >> q;
    int queries[q];
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }
    switchchanges(n, q, switches, queries);
    return 0;
}