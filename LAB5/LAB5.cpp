#include <bits/stdc++.h>

using namespace std;

// Utility function
double getAngle(pair<double, double> median, pair<double, double> a)
{
    return atan2(a.second - median.second, a.first - median.first);
}

void sortCoordinates(vector<pair<double, double>> &vectices)
{
    // Find median coordinate
    pair<double, double> median = make_pair(0.0, 0.0);

    for (auto i : vectices)
    {
        median.first += i.first;
        median.second += i.second;
    }

    median.first /= vectices.size();
    median.second /= vectices.size();

    // Sort coordinates counter-clockwise
    sort(vectices.begin(), vectices.end(), [median](pair<double, double> a, pair<double, double> b)
         { return getAngle(median, a) < getAngle(median, b); });
}

void printTriangulation(vector<vector<int>> &triangular, int i, int k)
{
    if (k < i + 2)
    {
        return;
    }

    int j = triangular[i][k];
    cout << i << " " << j << " " << k << endl;

    printTriangulation(triangular, i, j);
    printTriangulation(triangular, j, k);
}
// End of utility function

double distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double cost(vector<pair<double, double>> &vectices, int i, int j, int k)
{
    return distance(vectices[i], vectices[j]) + distance(vectices[j], vectices[k]) + distance(vectices[k], vectices[i]);
}

double minTriangulation(vector<pair<double, double>> &vectices, int i, int k, vector<vector<double>> &dp, vector<vector<int>> &triangular)
{
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }

    if (k < i + 2)
    {
        dp[i][k] = 0;
        return 0;
    }

    double minCost = INT_MAX;

    for (int j = i + 1; j < k; j++)
    {
        double calculatedCost = minTriangulation(vectices, i, j, dp, triangular) + minTriangulation(vectices, j, k, dp, triangular) + cost(vectices, i, j, k);
        if (calculatedCost < minCost)
        {
            triangular[i][k] = j;
            minCost = calculatedCost;
        }
    }

    dp[i][k] = minCost;
    return minCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input number of vertices
    int nVertices;
    cin >> nVertices;

    // Input coordinates
    vector<pair<double, double>> vectices = vector<pair<double, double>>(nVertices);
    for (int i = 0; i < nVertices; i++)
    {
        double x, y;
        cin >> x >> y;
        vectices[i] = make_pair(x, y);
    }

    // Sort coordinates counter-clockwise
    // sortCoordinates(vectices);

    // Initialize dp and triangular table
    vector<vector<double>> dp = vector<vector<double>>(nVertices, vector<double>(nVertices, -1));
    vector<vector<int>> triangular = vector<vector<int>>(nVertices, vector<int>(nVertices, -1));

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    double minCost = minTriangulation(vectices, 0, nVertices - 1, dp, triangular);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    chrono::duration<double> time = chrono::duration_cast<chrono::duration<double>>(end - start);

    // cast to microseconds
    cout << "Time: " << time.count() * 1000000 << "\u03BCs" << endl;

    cout << "Min cost: " << setprecision(10) << minCost << endl;

    cout << "Triangulation: \n";
    printTriangulation(triangular, 0, nVertices - 1);

    cout << "Sorted coordinates: \n";
    for (int i = 0; i < nVertices; i++)
    {
        cout << "[" << i << "] " << vectices[i].first << " " << vectices[i].second << endl;
    }

    return 0;
}