#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &graph, int u, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            DFS(graph, v, visited, st);
        }
    }

    st.push(u);
}

void DFSUtil(vector<vector<int>> &graph, int u, vector<bool> &visited, vector<int> &component)
{
    // 1. Mark the current node as visited
    visited[u] = true;

    // 2. Add the current node to the component
    component.push_back(u);

    // 3. For each neighbor of the current node, call DFSUtil() if it has not been visited
    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            DFSUtil(graph, v, visited, component);
        }
    }
}

vector<vector<int>> findStronglyConnectedComponents(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;

    // First DFS to create the stack
    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, st);
        }
    }

    // Create the transpose of the graph
    vector<vector<int>> GT(n, vector<int>());
    for (int u = 1; u < n; u++)
    {
        for (auto v : graph[u])
        {
            GT[v].push_back(u);
        }
    }

    // Second DFS to find the SCCs
    vector<vector<int>> SCCs;
    visited.assign(n, false);

    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (!visited[u])
        {
            vector<int> component;
            DFSUtil(GT, u, visited, component);
            SCCs.push_back(component);
        }
    }

    return SCCs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nVertices, nEdges;

    scanf("%d %d", &nVertices, &nEdges); // First input

    while (nVertices != 0 && nEdges != 0)
    {

        // Adjacency List
        vector<vector<int>> graph(nVertices + 1, vector<int>());

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
                graph[src].push_back(dest);
            }
            else if (direction == 2)
            {
                graph[src].push_back(dest);
                graph[dest].push_back(src);
            }
        }

        vector<vector<int>> SCCs = findStronglyConnectedComponents(graph);

        printf("Number of strongly connected components: %d\n", SCCs.size());
        for (auto SCC : SCCs)
        {
            for (int i = 0; i < SCC.size(); i++)
            {
                printf("%d ", SCC[i]);
            }
            printf("\n");
        }

        if (SCCs.size() == 1)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }

        scanf("%d %d", &nVertices, &nEdges); // Next input
    }

    return 0;
}