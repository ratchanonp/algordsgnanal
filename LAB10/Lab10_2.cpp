#include <bits/stdc++.h>

using namespace std;

typedef struct Edge
{
    int src, dest;
} Edge;

vector<Edge> getEdges(vector<vector<int>> &graph)
{
    vector<Edge> edges;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = i + 1; j < graph.size(); j++)
        {
            if (graph[i][j] == 1)
            {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edges.push_back(edge);
            }
        }
    }
    return edges;
}

vector<int> minVertexCover(vector<vector<int>> &graph)
{

    /**
     * NOTE: Approximation algorithm for Vertex Cover
     * C = empty set
     * E' = E
     * while E' != empty set
     *    let (u, v) be an arbitrary edge of E'
     *    C = C U {u, v}
     *    remove from E' every edge incident on either u or v
     * return C
     */

    vector<int> vertexCover;
    vector<Edge> edges = getEdges(graph);

    while (!edges.empty())
    {
        Edge edge = edges.back();
        edges.pop_back();

        vertexCover.push_back(edge.src);
        vertexCover.push_back(edge.dest);

        for (auto it = edges.begin(); it != edges.end();)
        {
            if (it->src == edge.src || it->src == edge.dest || it->dest == edge.src || it->dest == edge.dest)
            {
                it = edges.erase(it);
            }
            else
            {
                it++;
            }
        }
    }

    return vertexCover;
}

int main()
{

    vector<vector<int>> graph;

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

    string line;
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

    vector<int> vertexCover = minVertexCover(graph);
    sort(vertexCover.begin(), vertexCover.end());

    int nVertexCover = vertexCover.size();

    for (auto vertex : vertexCover)
    {
        cout << vertex << " ";
    }
    cout << endl;
    cout << nVertexCover << endl;

    return 0;
}