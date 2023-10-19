def transitive_closure(adjMatrix, nVertices):
    closure = [[[False for _ in range(nVertices + 1)] for _ in range(nVertices + 1)] for _ in range(nVertices + 1)]

    # Closure of length 0 is just the adjacency matrix
    for i in range(1, nVertices + 1):
        for j in range(1, nVertices + 1):
            closure[0][i][j] = adjMatrix[i][j] == 1 or (i == j)

    # Compute the closure for lengths 1 through nVertices
    for k in range(1, nVertices + 1):
        for i in range(1, nVertices + 1):
            for j in range(1, nVertices + 1):
                closure[k][i][j] = closure[k - 1][i][j] or (closure[k - 1][i][k] and closure[k - 1][k][j])

    # Return the final result
    return closure[nVertices]


# First input
nVertices, nEdges = map(int, input().split())

while nVertices != 0 and nEdges != 0:
    # Adjacency matrix initial value is 0
    adjMatrix = [[0 for _ in range(nVertices + 1)] for _ in range(nVertices + 1)]

    # Read edges
    # 1 - Mean there is an edge between two vertices from src to dest
    # 2 - Mean there is no edge between two vertices from src to dest both ways
    for _ in range(nEdges):
        src, dest, direction = map(int, input().split())
        if direction == 1:
            adjMatrix[src][dest] = 1
        elif direction == 2:
            adjMatrix[src][dest] = 1
            adjMatrix[dest][src] = 1

    transitive_closure_result = transitive_closure(adjMatrix, nVertices)

    # Check every vertices is reachable from every vertices
    isStrongConnected = True
    for i in range(1, nVertices + 1):
        for j in range(1, nVertices + 1):
            if not transitive_closure_result[i][j]:
                isStrongConnected = False
                break

    if isStrongConnected:
        print('1')
    else:
        print('0')

    # Next input
    nVertices, nEdges = map(int, input().split())
