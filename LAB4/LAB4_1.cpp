#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &coins, int n, int sum, vector<vector<int>> &dp)
{
    // Base Case
    if (sum == 0)
    {
        return dp[n][sum] = 1;
    }

    // If number of coins is 0 or sum is less than 0 then
    // there is no way to make the sum.
    if (n == 0 || sum < 0)
        return 0;

    // If the subproblem is previously calculated then
    // simply return the result
    if (dp[n][sum] != -1)
    {

        if (dp[n][sum] > 0)
        {
            return dp[n][sum];
        }
    }

    // Two options for the current coin
    // Include the current coin
    int include = count(coins, n, sum - coins[n - 1], dp);

    // Exclude the current coin
    int exclude = count(coins, n - 1, sum, dp);

    return dp[n][sum] = include + exclude;
}

void displayDenomination(vector<vector<int>> &denomination)
{
    printf("Denomination: ");
    for (int i = 0; i < denomination.size(); i++)
    {
        printf("(");
        for (int j = 0; j < denomination[i].size(); j++)
        {
            printf("%d", denomination[i][j]);
            if (j < denomination[i].size() - 1)
                printf(", ");
        }
        printf(")");
        if (i < denomination.size() - 1)
            printf(", ");
    }

    printf("\n");
}

void displayTime(chrono::nanoseconds duration)
{
    printf("Time taken: ");
    if (duration.count() < 1000)
        printf("%'ld ns\n", duration.count());
    else if (duration.count() < 1000000)
        printf("%'ld \u03BCs\n", chrono::duration_cast<chrono::microseconds>(duration).count());
    else if (duration.count() < 1000000000)
        printf("%'ld ms\n", chrono::duration_cast<chrono::milliseconds>(duration).count());
    else
        printf("%'ld s\n", chrono::duration_cast<chrono::seconds>(duration).count());
}

void displayTable(vector<vector<int>> &dp, vector<int> &coins)
{
    int n = dp.size();
    int sum = dp[0].size();

    // Display the table header
    for (int i = -1; i < sum; i++)
    {
        printf("%3d ", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            printf("%3d ", coins[i - 1]);
        else
            printf("%3d ", 0);

        for (int j = 0; j < sum; j++)
        {
            // if (dp[i][j] <= 0)
            //     printf("%3s ", " ");
            // else
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int amount;
    vector<int> coins;

    cin >> amount;

    // read until EOF
    while (cin.good())
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    int n = coins.size();

    printf("Amount: %d\n", amount);
    // printf("Coins: ");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", coins[i]);
    // printf("\n");

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    auto start = chrono::high_resolution_clock::now();
    int result = count(coins, n, amount, dp);
    auto end = chrono::high_resolution_clock::now();

    printf("Number of ways: %d\n", result);

   
    //displayDenomination(denomination);
    displayTime(end - start);
    // displayTable(dp, coins);

    printf("\n");

    return 0;
}