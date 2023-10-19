#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> transitive_closure(vector<vector<int>> adjMatrix, int nVertices)
{
    vector<vector<vector<bool>>> closure(nVertices + 1, vector<vector<bool>>(nVertices + 1, vector<bool>(nVertices + 1, false)));

    // Closure of length 0 is just the adjacency matrix
    for (int i = 1; i <= nVertices; i++)
    {
        for (int j = 1; j <= nVertices; j++)
        {
            closure[0][i][j] = adjMatrix[i][j] == 1 || (i == j);
        }
    }

    // Compute the closure for lengths 1 through nVertices
    for (int k = 1; k <= nVertices; k++)
    {
        for (int i = 1; i <= nVertices; i++)
        {
            for (int j = 1; j <= nVertices; j++)
            {
                closure[k][i][j] = closure[k - 1][i][j] || (closure[k - 1][i][k] && closure[k - 1][k][j]);
            }
        }
    }

    // Return the final result
    return closure[nVertices];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie();

    int nVertices, nEdges;

    scanf("%d %d", &nVertices, &nEdges); // First input

    while (nVertices != 0 && nEdges != 0)
    {

        // Adjacency matrix initial value is 0
        vector<vector<int>> adjMatrix(nVertices + 1, vector<int>(nVertices + 1, 0));

        /*
            Read edges
            1 - Mean there is an edge between two vertices from src to dest
            2 - Mean there is no edge between two vertices from src to dest both ways
        */
        for (int i = 0; i < nEdges; i++)
        {
            int src, dest, direction;
            scanf("%d %d %d", &src, &dest, &direction);

            if (direction == 1)
            {
                adjMatrix[src][dest] = 1;
            }
            else if (direction == 2)
            {
                adjMatrix[src][dest] = 1;
                adjMatrix[dest][src] = 1;
            }
        }

        vector<vector<bool>> transitive_closure_result = transitive_closure(adjMatrix, nVertices);

        // Check every vertices is reachable from every vertices
        bool isStrongConnected = true;
        for (int i = 1; i <= nVertices; i++)
        {
            for (int j = 1; j <= nVertices; j++)
            {
                if (!transitive_closure_result[i][j])
                {
                    isStrongConnected = false;
                    break;
                }
            }
        }

        if (isStrongConnected)
            printf("1\n");
        else
            printf("0\n");

        scanf("%d %d", &nVertices, &nEdges); // Next input
    }

    return 0;
}