#include <bits/stdc++.h>

using namespace std;

int cntOdd = 0;
int cntEven = 0;

void PatternOdd(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return;
    }

    arr[start] = cntOdd * 2 + 1;
    cntOdd++;

    int mid = (start + end) / 2;

    PatternOdd(arr, start + 1, mid);
    PatternOdd(arr, mid + 1, end);
}

void PatternEven(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return;
    }

    arr[end] = cntEven * 2;
    cntEven++;

    int mid = (start + end) / 2;

    PatternEven(arr, start, mid - 1);
    PatternEven(arr, mid, end - 1);
}

void Pattern(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    PatternEven(arr, start, mid);
    PatternOdd(arr, mid + 1, end);
}

int main()
{
    int n = 0;
    // cin >> n;
    while (n <= 20)
    {
        vector<int> arr(n + 1);

        cntEven = 0;
        cntOdd = 0;

        Pattern(arr, 0, n);

        for (auto i : arr)
        {
            printf("%d ", i);
        }

        cout << endl;

        n += 2;
    }

    return 0;
}