class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int divisibleIslandsCount = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) {
                    int islandRemainder = grid[r][c] % k;
                    queue<pair<int, int>> q;
                    
                    q.push({r, c});
                    grid[r][c] = -1; // Mark as visited

                    while (!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();

                        for (auto& dir : directions) {
                            int nr = currR + dir.first;
                            int nc = currC + dir.second;

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                islandRemainder = (islandRemainder + grid[nr][nc]) % k;
                                grid[nr][nc] = -1; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (islandRemainder == 0) {
                        divisibleIslandsCount++;
                    }
                }
            }
        }
        return divisibleIslandsCount;
    }
};