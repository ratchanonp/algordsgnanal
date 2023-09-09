#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &coins, int n, int sum, vector<vector<int>> &dp)
{
    // Base Case
    if (sum == 0)
        return dp[n][sum] = 1;

    // If number of coins is 0 or sum is less than 0 then
    // there is no way to make the sum.
    if (n == 0 || sum < 0)
        return 0;

    // If the subproblem is previously calculated then
    // simply return the result
    if (dp[n][sum] != -1)
        return dp[n][sum];

    // Two options for the current coin
    return dp[n][sum] = count(coins, n, sum - coins[n - 1], dp) + count(coins, n - 1, sum, dp);
}

tuple<int, vector<int>> readFile(string filepath)
{
    ifstream testCaseFile(filepath);

    int amount;
    vector<int> coins;

    if (testCaseFile.is_open())
    {
        string line;
        getline(testCaseFile, line);

        amount = stoi(line);

        getline(testCaseFile, line);
        stringstream ss(line);

        while (ss.good())
        {
            string substr;
            getline(ss, substr, ' ');

            if (substr != "")
                coins.push_back(stoi(substr));
        }
    }
    else
        cout << "Unable to open file";

    return make_tuple(amount, coins);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int amount;
    vector<int> coins;
    tie(amount, coins) = readFile("./test/4.14(Extra).txt");

    int n = coins.size();

    printf("Amount: %d\n", amount);
    printf("Coins %d: ", n);
    for (int i = 0; i < n; i++)
        printf("%d ", coins[i]);

    printf("\n");

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    auto start = chrono::high_resolution_clock::now();
    printf("Number of ways: %'d\n", count(coins, n, amount, dp));
    auto end = chrono::high_resolution_clock::now();
    printf("Time taken: %'ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());

    return 0;
}