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

            // cout << n1 << " " << seq[i] << " " << n3 << endl;

            triplets.push_back(make_tuple(n1, seq[i], n3));

            n1_index--;
            n3_index++;
        }
    }

    return triplets;
}

vector<int> sortSeq(vector<int> seq, vector<tuple<int, int, int>> triplets)
{
    vector<int> result;

    for (auto triplet : triplets)
    {
        vector<int> copySeq(seq);

        int n1 = get<0>(triplet);
        int n2 = get<1>(triplet);
        int n3 = get<2>(triplet);

        sort(copySeq.begin(), copySeq.end(), [n1, n2, n3](int a, int b)
             {
                if (a == n2) return false;
                if (b == n2) return true;
                if (a == n1 || a == n3) return true;
                if (b == n1 || b == n3) return false;
                return a > b; });

        cout << "====================" << endl;
        cout << "n1: " << n1 << " n2: " << n2 << " n3: " << n3 << endl;
        for (auto i : copySeq)
        {
            cout << i << " ";
        }

        cout << endl;
        cout << validate(copySeq, triplets) << endl;

        if (validate(copySeq, triplets))
        {
            result = copySeq;
            break;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<int> seq(n + 1);
    iota(seq.begin(), seq.end(), 0);

    vector<tuple<int, int, int>> triplets = generateTriplets(seq);

    for (auto triplet : triplets)
    {
        cout << get<0>(triplet) << " " << get<1>(triplet) << " " << get<2>(triplet) << endl;
    }

    // generate all permutations of seq
    vector<vector<int>> permutations;

    vector<int> check = {0, 8, 4, 12, 2, 10, 14, 6, 9, 1, 5, 3, 13, 11, 7};

    if (validate(check, triplets))
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    // for (auto currentSeq : permutations)
    // {
    //     if (validate(currentSeq, triplets))
    //     {
    //         for (auto i : currentSeq)
    //         {
    //             cout << i << " ";
    //         }

    //         cout << endl;
    //         break;
    //     }
    // // }

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "It took me " << time_span.count() << " seconds." << endl;

    // vector<int> sortedSeq = sortSeq(seq, triplets);

    // for (int i : sortedSeq)
    // {
    //     cout << i << " ";
    // }

    // cout << endl;

    return 0;
}