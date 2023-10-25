#include <bits/stdc++.h>

using namespace std;

// Function prototypes
void printMatrix(vector<vector<int>> &matrix);
void printPath(vector<vector<int>> &predecessor, int src, int dest);
void addEdge(vector<vector<int>> &adjMatrix, int src, int dest, int weight);
void solve(vector<vector<int>> dist, vector<vector<int>> predecessor, int src, int dest);
pair<vector<vector<int>>, vector<vector<int>>> floydWarshall(vector<vector<int>> adjMatrix);

void printMatrix(vector<vector<int>> &matrix)
{
    int nVerticecs = matrix.size();

    for (int i = 0; i < nVerticecs; i++)
    {
        printf("%3d |", i);
    }

    printf("\n");

    for (int i = 0; i < nVerticecs; i++)
    {
        printf("-----", i);
    }

    printf("\n");

    for (int i = 1; i < nVerticecs; i++)
    {
        printf("%3d |", i);

        for (int j = 1; j < nVerticecs; j++)
        {
            printf("%3d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printPath(vector<vector<int>> &predecessor, int src, int dest)
{

    if (src == dest)
    {
        cout << src << " ";
    }
    else if (predecessor[src][dest] == -1)
    {
        cout << "no path";
    }
    else
    {
        printPath(predecessor, src, predecessor[src][dest]);
        cout << dest << " ";
    }
}

void addEdge(vector<vector<int>> &adjMatrix, int src, int dest, int weight)
{
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight;
}

void solve(vector<vector<int>> dist, vector<vector<int>> predecessor, int src, int dest)
{
    if (dist[src][dest] != INT_MAX)
    {
        cout << dist[src][dest] << " ";
        printPath(predecessor, src, dest);
        cout << endl;
    }
    else
    {
        cout << "no path" << endl;
    }
}

// Floyd-Warshall algorithm
pair<vector<vector<int>>, vector<vector<int>>> floydWarshall(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<vector<int>> predecessor(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (adjMatrix[i][j] != 0)
            {
                dist[i][j] = adjMatrix[i][j];
                predecessor[i][j] = i;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    int newDist = min(dist[i][j], max(dist[i][k], dist[k][j]));

                    if (newDist < dist[i][j])
                    {
                        dist[i][j] = newDist;
                        predecessor[i][j] = predecessor[k][j];
                    }
                }
            }
        }
    }

    return make_pair(dist, predecessor);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nVerticecs, nEdges;
    int nTest;

    cin >> nVerticecs >> nEdges >> nTest;

    nVerticecs++;

    // Adjacency matrix
    vector<vector<int>> adjMatrix(nVerticecs, vector<int>(nVerticecs, 0));

    // Read edges
    for (int i = 0; i < nEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;

        addEdge(adjMatrix, src, dest, weight);
    }

    vector<vector<int>> dist, predecessor;
    tie(dist, predecessor) = floydWarshall(adjMatrix);

    printMatrix(dist);
    printMatrix(predecessor);

    // Read tests
    for (int i = 0; i < nTest; i++)
    {
        int src, dest;
        cin >> src >> dest;

        solve(dist, predecessor, src, dest);
    }

    return 0;
}