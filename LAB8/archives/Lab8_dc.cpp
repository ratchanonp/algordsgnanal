#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &seq, int low, int high, int n1, int n2, int n3)
{
    int pivot = seq[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (seq[j] == n2)
            continue;
        if (seq[j] == n1 || seq[j] == n3 || seq[j] > pivot)
        {
            i++;
            swap(seq[i], seq[j]);
        }
    }
    swap(seq[i + 1], seq[high]);
    return (i + 1);
}

void quickSort(vector<int> &seq, int low, int high, int n1, int n2, int n3)
{
    if (low < high)
    {
        int pi = partition(seq, low, high, n1, n2, n3);
        quickSort(seq, low, pi - 1, n1, n2, n3);
        quickSort(seq, pi + 1, high, n1, n2, n3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n + 1);
    iota(seq.begin(), seq.end(), 0);

    // Pick any 3 numbers from seq
    int n1 = seq[1], n3 = seq[3];
    int n2 = (n1 + n3) / 2;

    quickSort(seq, 0, seq.size() - 1, n1, n2, n3);

    for (int i : seq)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}