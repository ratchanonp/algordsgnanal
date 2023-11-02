#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n + 1);
    iota(seq.begin(), seq.end(), 0);

    // Pick any 3 numbers from seq
    int n1 = seq[1], n2 = seq[2], n3 = seq[3];

    sort(seq.begin(), seq.end(), [n1, n2, n3](int a, int b)
         {
        if (a == n2) return false;
        if (b == n2) return true;
        if (a == n1 || a == n3) return true;
        if (b == n1 || b == n3) return false;
        return a > b; });

    for (int i : seq)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}