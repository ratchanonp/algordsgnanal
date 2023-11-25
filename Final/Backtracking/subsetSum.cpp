#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr, vector<int> &path, int pos, int targetSum) {
    // Copy the path for backtracking
    vector<int> temp = path;

    // If the target sum is reached
    if (targetSum == 0) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    // If the target sum cannot be reached
    if (targetSum < 0) {
        return;
    }

    // For all the elements
    for (int i = pos; i < arr.size(); i++) {
        // Push the element in the path
        path.push_back(arr[i]);

        // Call the function recursively
        solve(arr, path, i + 1, targetSum - arr[i]);

        // Backtrack
        path = temp;
    }

    return;
}

int main() {
    int n, targetSum;
    cin >> n >> targetSum;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> path;
    solve(arr, path, 0, targetSum);
}