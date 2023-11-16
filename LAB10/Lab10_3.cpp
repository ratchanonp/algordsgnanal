#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

vector<vector<int>> convertFrom3SatToVertexCoverGraph(vector<vector<int>> &clauses, int nVariable)
{
    int nClause = clauses.size();
    int nVertices = 2 * nVariable + 3 * nClause;

    vector<vector<int>> graph(nVertices, vector<int>(nVertices));

    /**
     * Example: 1 -2 3 means (x1 or not x2 or x3)
     */

    // 1. Add edges between variables
    for (int i = 0; i < nVariable; i++)
        addEdge(graph, 2 * i, 2 * i + 1);

    // 2. Create Clause Triangles and add edges between them
    int cluaseStartIndex = 2 * nVariable - 1;
    for (auto &clause : clauses)
    {
        for (int i = 0; i < 3; i++)
        {
            int literal = clause[i];
            int literalIndex = abs(literal) - 1;
            int literalVertex = literalIndex * 2 + (literal > 0 ? 0 : 1);

            addEdge(graph, cluaseStartIndex + i + 1, literalVertex);
        }

        cluaseStartIndex += 3;
    }

    // 3. Add edges between clause triangles
    for (int i = 2 * nVariable; i < nVertices; i += 3)
    {
        addEdge(graph, i, i + 1);
        addEdge(graph, i + 1, i + 2);
        addEdge(graph, i + 2, i);
    }

    return graph;
}

int main()
{

    int nClause, nVariable = INT_MIN;

    cin >> nClause;

    vector<vector<int>> clauses(nClause);

    for (int i = 0; i < nClause; i++)
    {
        int maxLiteral = INT_MIN;
        for (int j = 0; j < 3; j++)
        {
            int literal;
            cin >> literal;
            clauses[i].push_back(literal);

            maxLiteral = max(maxLiteral, abs(literal));
        }
        nVariable = max(nVariable, maxLiteral);
    }

    int nVertices = 2 * nVariable + 3 * nClause;
    int nVecticesOnVertexCover = nVariable + 2 * nClause;

    vector<vector<int>> graph;

    graph = convertFrom3SatToVertexCoverGraph(clauses, nVariable);

    cout << nVertices << endl;
    cout << nVecticesOnVertexCover << endl;
    for (auto &row : graph)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 *
1
1 -2 3
*/