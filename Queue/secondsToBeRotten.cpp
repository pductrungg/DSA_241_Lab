// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int freshApples = 0;
    queue<pair<int, int>> rottenApples;

    // Count fresh apples and enqueue rotten apples
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1)
                freshApples++;
            else if (grid[i][j] == 2)
                rottenApples.push({i, j});
        }
    }

    int time = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!rottenApples.empty() && freshApples > 0) {
        int size = rottenApples.size();
        for (int i = 0; i < size; ++i) {
            int x = rottenApples.front().first;
            int y = rottenApples.front().second;
            rottenApples.pop();

            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    rottenApples.push({nx, ny});
                    freshApples--;
                }
            }
        }
        time++;
    }

    return freshApples == 0 ? time : -1;}