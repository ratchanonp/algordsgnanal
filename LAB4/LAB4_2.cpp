#include <bits/stdc++.h>

using namespace std;

vector<int> coinSequence(int lastCoin[], int amount)
{
    vector<int> sequence;

    while (amount > 0)
    {
        sequence.push_back(lastCoin[amount]);
        amount -= lastCoin[amount];
    }

    return sequence;
}

vector<int> minimunCoinChange(int amount, vector<int> coins)
{

    int numCoins[amount + 1];
    int lastCoin[amount + 1];

    numCoins[0] = 0;
    lastCoin[0] = -1;

    for (int i = 1; i <= amount; i++)
    {
        numCoins[i] = INT_MAX;
        lastCoin[i] = -1;

        for (int j = 0; j < coins.size(); j++)
        {

            if (coins[j] <= i && numCoins[i - coins[j]] != INT_MAX)
            {
                numCoins[i] = numCoins[i - coins[j]] + 1;
                lastCoin[i] = coins[j];
            }
        }
    }

    if (numCoins[amount] == INT_MAX)
    {
        cout << "No solution" << endl;
        return {};
    }

    return coinSequence(lastCoin, amount);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int amount;
    vector<int> coins;

    cin >> amount;

    string line;
    getline(cin >> ws, line);

    // Split string by space and convert to int
    stringstream ss(line);
    int temp;
    while (ss >> temp)
    {
        coins.push_back(temp);
    }

    // Sort coins in descending order
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    sort(coins.begin(), coins.end(), less<int>());
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    vector<int> solution = minimunCoinChange(amount, coins);
    if (solution.empty())
    {
        return 0;
    }

    cout << "Amount: " << amount << endl;
    cout
        << "coins: ";
    for (auto coin : coins)
    {
        cout << coin << " ";
    }
    cout << endl;
    cout << "minimum number of coins: " << solution.size() << "\n";
    cout << "coins: ";
    for (auto coin : solution)
    {
        cout << coin << " ";
    }
    cout << endl;
    cout << "Time: " << time_span.count() << " seconds" << endl;

    return 0;
}