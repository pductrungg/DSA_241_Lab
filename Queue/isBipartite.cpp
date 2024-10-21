bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> colors(n, -1); // Initialize colors of all nodes to -1 (unvisited)
    
    // Perform BFS on each connected component of the graph
    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) { // If the node is unvisited
            queue<int> q;
            q.push(i); // Start BFS from this node
            colors[i] = 0; // Color the node with color 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                // Assign alternate color to its neighbors
                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) { // If neighbor is unvisited
                        colors[neighbor] = 1 - colors[node]; // Assign alternate color
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) {
                        // If neighbor has same color as current node, graph is not bipartite
                        return false;
                    }
                }
            }
        }
    }

    // If all connected components are bipartite, the graph is bipartite
    return true;
}