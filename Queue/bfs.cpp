void bfs(vector<vector<int>> graph, int start) {
	    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    // Enqueue the start node and mark it as visited
    q.push(start);
    visited[start] = true;

    // Continue traversal until queue is empty
    while (!q.empty()) {
        // Dequeue a node from the queue
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Enqueue all adjacent nodes of the dequeued node
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}