// A Top-Down DP implementation
// of LCS problem
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for X[0..m-1],
// Y[0..n-1]
int lcs(char* X, char* Y, int m, int n,
		vector<vector<int> >& dp)
{
	if (m == 0 || n == 0)
        return 0;

	if (X[m - 1] == Y[n - 1])
		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

	// if (dp[m][n] != -1) {
	// 	return dp[m][n];
	// }

	return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
						lcs(X, Y, m - 1, n, dp));
}

// Print DP table
void printDP(vector<vector<int> >& dp, string X, string Y)
{
    printf(" ");
    for (int i = 0; i < Y.size(); i++)
        printf("%3c", Y[i]);
    cout << endl;
    for (int i = 0; i < dp.size(); i++) {
        if (i > 0)
            cout << X[i - 1] << " ";
        else
            cout << "  ";
        for (int j = 1; j < dp[i].size(); j++) {
            printf("%2d ", dp[i][j]);
        }
        cout << endl;
    }
}

string printLCS(vector<vector<int> >& dp, string X, string Y)
{
    int i = X.size();
    int j = Y.size();
    string res = "";
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            res += X[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void printSCS(vector<vector<int> >& dp, string X, string Y, string LCS)
{
    int i = 0;
    int j = 0;
    int k = 0;
    string res = "";
    while (i < X.size() && j < Y.size()) {
        if (X[i] == LCS[k] && Y[j] == LCS[k]) {
            res += LCS[k];
            i++;
            j++;
            k++;
        }
        else {
            if (X[i] == LCS[k]) {
                res += Y[j];
                j++;
            }
            else if (Y[j] == LCS[k]) {
                res += X[i];
                i++;
            }
            else {
                res += X[i];
                res += Y[j];
                i++;
                j++;
            }
        }
    }
    while (i < X.size()) {
        res += X[i];
        i++;
    }
    while (j < Y.size()) {
        res += Y[j];
        j++;
    }

    cout << "i" << i << " j" << j << " k" << k << endl;

    cout << "SCS is " << res << endl;
}

// Driver code
int main()
{
	char X[] = "ABCCD";
	char Y[] = "BCDEF";

	int m = strlen(X);
	int n = strlen(Y);
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	
    cout << "Length of LCS is " << lcs(X, Y, m, n, dp) << endl;

    printDP(dp, X, Y);
    string LCS = printLCS(dp, X, Y);
    cout << "LCS is " << LCS << endl;
    printSCS(dp, X, Y, LCS);

	return 0;
}
