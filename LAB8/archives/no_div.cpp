#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> arr)
{
    for (auto i : arr)
    {
        printf("%d ", i);
    }
    cout << endl;
}

vector<int> DaC(vector<int> arr)
{
    if (arr.size() == 1)
        return arr;

    // Left size Odd index
    vector<int> left;
    // Right size Even index
    vector<int> right;

    int i = 0;
    for (i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            left.push_back(arr[i]);
        }
        else
        {
            right.push_back(arr[i]);
        }
    }

    // cout << "Before:" << endl;
    // cout << "Left: ";
    // printVector(left);
    // cout << "Right: ";
    // printVector(right);
    // cout << "-------------------" << endl;

    left = DaC(left);
    right = DaC(right);

    // cout << "After:" << endl;
    // cout << "Left: ";
    // printVector(left);
    // cout << "Right: ";
    // printVector(right);
    // cout << "==================" << endl;

    left.insert(left.end(), right.begin(), right.end());

    return left;
}

int main()
{
    // int n = 0;
    // // cin >> n;
    // while (n <= 20)
    // {

    int n;
    cin >> n;

    // Create a vector of size n + 1
    vector<int> arr(n + 1);

    iota(arr.begin(), arr.end(), 0);

    arr = DaC(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }

    cout << endl;

    //     n += 2;
    // }

    return 0;
}