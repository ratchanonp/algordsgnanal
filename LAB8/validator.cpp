#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> generateTriplets(vector<int> seq)
{
    vector<tuple<int, int, int>> triplets;

    int n = seq.size() - 1;

    for (int i = 1; i < n; i++)
    {

        int n1_index = i - 1;
        int n3_index = i + 1;

        while (n1_index >= 0 && n3_index <= n)
        {
            int n1 = seq[n1_index];
            int n3 = seq[n3_index];

            // cout << n1 << " " << seq[i] << " " << n3 << endl;

            triplets.push_back(make_tuple(n1, seq[i], n3));

            n1_index--;
            n3_index++;
        }
    }

    return triplets;
}

void sort(vector<int> &seq)

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n + 1);
    iota(seq.begin(), seq.end(), 0);

        return 0;
}