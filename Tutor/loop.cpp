#include <bits/stdc++.h>

using namespace std;

int main()
{

    int i = 1;

    for (i; i <= 10;)
    {
        cout << i << endl;

        int k = 1;
        for (k; k <= i;)
        {
            cout << k << " ";
            k = k + 1;
        }
        cout << endl;
        i = i + 1;
    }

    return 0;
}