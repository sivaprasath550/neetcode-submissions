// class Solution {
// public:
//     int dfs(int row, int col, int n, int m, vector<vector<int>>& grid, int ans){

//         if(grid[row][col] == 0){
//             return ans;
//         }

//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, -1, 0, 1};
//         int mini = INT_MAX;

//         for(int i = 0; i < 4; i++){
//           int nr = dr[i] + row;
//           int nc = dc[i] + col;

//           if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1){
//             while(grid[nr][nc] == 0){

//                 int ans = dfs(nr, nc, n, m, grid, ans + 1);
//             }
//           }

//           mini = min(mini, ans);
//           grid[nr][nc] = mini;
//         }
//     }

//     void islandsAndTreasure(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int ans = 0;

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){

//                 if(grid[i][j] == INF){
//                     dfs(i, j, n, m, grid, ans);
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int INF = 2147483647;

        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for(int i = 0; i < 4; i++){
                int nr = dr[i] + row;
                int nc = dc[i] + col;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == INF){

                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
