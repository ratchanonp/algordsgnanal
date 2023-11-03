#include <bits/stdc++.h>

using namespace std;

// Function prototype
vector<int> mergeCustomSort(vector<int> left, vector<int> right);
vector<int> customSort(vector<int> arr);
vector<int> getLeft(vector<int> arr);
vector<int> getRight(vector<int> arr);

vector<int> mergeCustomSort(vector<int> left, vector<int> right)
{
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

vector<int> customSort(vector<int> arr)
{
    if (arr.size() == 1) return arr;

    vector<int> left = getLeft(arr);
    vector<int> right = getRight(arr);

    left = customSort(left);
    right = customSort(right);

    return mergeCustomSort(left, right);
}

vector<int> getLeft(vector<int> arr)
{
    vector<int> left;
    for (int i = 0; i < arr.size(); i += 2) left.push_back(arr[i]);
    return left;
}

vector<int> getRight(vector<int> arr)
{
    vector<int> right;
    for (int i = 1; i < arr.size(); i += 2) right.push_back(arr[i]);
    return right;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    iota(arr.begin(), arr.end(), 0);

    arr = customSort(arr);

    for (auto i : arr)cout << i << " ";

    cout << endl;

    return 0;
}