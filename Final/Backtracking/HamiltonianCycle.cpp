#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> &graph, vector<int> &path, int v, int pos, vector<bool> &visited)
{
    // Copy the path for backtracking
    vector<int> temp = path;

    // If all the vertices are visited and the last vertex is connected to the first vertex
    if (pos == v && find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), path[0]) != graph[path[pos - 1]].end())
    {
        for (int i = 0; i < v; i++)
        {
            printf("%c ", path[i] + 'A');
        }
        cout << endl;
        return;
    }

    // If all the vertices are visited but the last vertex is not connected to the first vertex
    if (pos == v)
    {
        return;
    }

    // For all the vertices
    for (int i = 0; i < v; i++)
    {
        // If the vertex is not visited and the vertex is connected to the last vertex
        if (!visited[i] && find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), i) != graph[path[pos - 1]].end())
        {
            // Mark the vertex as visited
            visited[i] = true;

            // Push the vertex in the path
            path.push_back(i);

            // Call the function recursively
            solve(graph, path, v, pos + 1, visited);

            // Backtrack
            path = temp;
            visited[i] = false;
        }
    }

    return;
}

int main()
{
    int v;
    cin >> v;

    // Adjacency list
    vector<vector<int>> graph(v);

    // Input the graph
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int weight;
            cin >> weight;
            if (weight == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    vector<int> path;
    vector<bool> visited(v, false);
    visited[0] = true;
    path.push_back(0);
    solve(graph, path, v, 1, visited);
}