#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &coins, int n, int sum, vector<vector<int>> &dp, vector<vector<int>> &denomination, vector<int> &temp_denomination)
{
    // Base Case
    if (sum == 0)
    {
        denomination.push_back(temp_denomination);
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
            denomination.push_back(temp_denomination);
        return dp[n][sum];
    }

    // Two options for the current coin
    temp_denomination.push_back(coins[n - 1]);
    int include = count(coins, n, sum - coins[n - 1], dp, denomination, temp_denomination);

    temp_denomination.pop_back();
    int exclude = count(coins, n - 1, sum, dp, denomination, temp_denomination);

    return dp[n][sum] = include + exclude;
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

vector<string> getAllTestCaseFile(string folderPath)
{
    vector<string> files;
    for (const auto &entry : filesystem::directory_iterator(folderPath))
    {
        files.push_back(entry.path());
    }

    sort(files.begin(), files.end(), [](const string &a, const string &b)
         { return stoi(a.substr(a.find_last_of("/\\") + 1).substr(2, 3)) > stoi(b.substr(b.find_last_of("/\\") + 1).substr(2, 3)); });

    return files;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> files = getAllTestCaseFile("./test");
    // vector<string> files;
    // files.push_back("./test/4.0.txt");

    while (!files.empty())
    {
        string filepath = files.back();
        files.pop_back();

        printf("File: %s\n", filepath.c_str());

        int amount;
        vector<int> coins;
        tie(amount, coins) = readFile(filepath);

        int n = coins.size();

        printf("Amount: %d\n", amount);
        // printf("Coins: ");
        // for (int i = 0; i < n; i++)
        //     printf("%d ", coins[i]);
        // printf("\n");

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        vector<vector<int>> denomination;
        vector<int> temp_denomination;

        auto start = chrono::high_resolution_clock::now();
        printf("Number of ways: %'d\n", count(coins, n, amount, dp, denomination, temp_denomination));
        auto end = chrono::high_resolution_clock::now();

        // Display Denomination
        // displayDenomination(denomination);
        displayTime(end - start);
        // displayTable(dp, coins);

        printf("\n");
    }
    return 0;
}