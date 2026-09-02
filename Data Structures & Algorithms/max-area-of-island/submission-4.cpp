class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        int maxi = 0;

        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 1 && !vis[r][c]) {

                    int ans = bfs(
                        grid,
                        r,
                        c,
                        vis,
                        directions,
                        rows,
                        cols
                    );

                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }

private:
    int bfs(
        vector<vector<int>>& grid,
        int r,
        int c,
        vector<vector<bool>>& vis,
        vector<pair<int, int>>& directions,
        int rows,
        int cols
    ) {

        queue<pair<int, int>> q;

        q.push({r, c});
        vis[r][c] = true;

        int area = 1;

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {

                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1 &&
                    !vis[nr][nc]) {

                    q.push({nr, nc});
                    vis[nr][nc] = true;

                    area++;
                }
            }
        }

        return area;
    }
};