
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> KVertexCover(vector<vector<int>> &graph, int k)
{
    vector<vector<int>> vertexCoverList;
    vector<int> vertexCover;

    int nVertices = graph.size();

    int verices[nVertices];
    iota(verices, verices + nVertices, 0);

    vector<bool> v(nVertices);
    fill(v.begin(), v.begin() + k, true);

    do
    {
        vertexCover.clear();
        for (int i = 0; i < nVertices; ++i)
        {
            if (v[i])
            {
                vertexCover.push_back(verices[i]);
            }
        }

        bool isVertexCover = true;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = i + 1; j < nVertices; j++)
            {
                if (graph[i][j] == 1 &&
                    find(vertexCover.begin(), vertexCover.end(), i) == vertexCover.end() &&
                    find(vertexCover.begin(), vertexCover.end(), j) == vertexCover.end())
                {
                    isVertexCover = false;
                    break;
                }
            }
            if (!isVertexCover)
            {
                break;
            }
        }

        if (isVertexCover)
        {
            vertexCoverList.push_back(vertexCover);
        }
    } while (prev_permutation(v.begin(), v.end()));

    return vertexCoverList;
}

int main()
{
    int k;
    vector<vector<int>> graph;

    // Get file path
    string filePath;
    cout << "Enter file path: ";
    cin >> filePath;

    // Read file
    ifstream file(filePath);
    if (!file.is_open())
    {
        cout << "File not found!" << endl;
        return 0;
    }

    // First line: k
    string line;
    getline(file, line);

    k = stoi(line);

    // Read Adjacency matrix
    while (getline(file, line))
    {
        vector<int> adjacencyList;
        stringstream ss(line);
        int weight;
        while (ss >> weight)
        {
            adjacencyList.push_back(weight);
        }
        graph.push_back(adjacencyList);
    }

    vector<vector<int>> vertexCoverList = KVertexCover(graph, k);
    int nVertexCover = vertexCoverList.size();
    if (nVertexCover == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << nVertexCover << endl;
        for (auto vertexCover : vertexCoverList)
        {
            for (auto vertex : vertexCover)
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
}