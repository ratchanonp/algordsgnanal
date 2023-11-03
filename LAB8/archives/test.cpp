#include <bits/stdc++.h>

using namespace std;

bool validate(vector<int> seq, vector<tuple<int, int, int>> triplets)
{
    for (auto triplet : triplets)
    {
        int n1 = get<0>(triplet);
        int n2 = get<1>(triplet);
        int n3 = get<2>(triplet);

        int index_n1 = find(seq.begin(), seq.end(), n1) - seq.begin();
        int index_n2 = find(seq.begin(), seq.end(), n2) - seq.begin();
        int index_n3 = find(seq.begin(), seq.end(), n3) - seq.begin();

        // Check n2 is not in between n1 and n3
        if (index_n1 < index_n2 && index_n2 < index_n3)
        {
            cout << n2 << " is in between " << n1 << " and " << n3 << endl;
            return false;
        }
        else if (index_n1 > index_n2 && index_n2 > index_n3)
        {
            cout << n2 << " is in between " << n1 << " and " << n3 << endl;
            return false;
        }
    }

    return true;
}

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

            triplets.push_back(make_tuple(n1, seq[i], n3));

            n1_index--;
            n3_index++;
        }
    }

    return triplets;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> seq(n + 1);
    iota(seq.begin(), seq.end(), 0);
    vector<tuple<int, int, int>> triplets = generateTriplets(seq);

    vector<int> check(n + 1);

    cout << "Enter seq. for check: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> check[i];
    }

    if (validate(check, triplets))
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "It took me " << time_span.count() << " seconds." << endl;

    return 0;
}