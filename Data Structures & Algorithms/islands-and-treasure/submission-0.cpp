class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       queue<pair<int, int>>q;

       int row = grid.size();
       int col = grid[0].size();

       if(row == 0) return;

       for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 0)
              q.push({i, j});
        }
       }

       vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

       while(!q.empty()){
         auto [r, c] = q.front();
         q.pop();

         for(auto d : dirs){
            int nr = r + d.first;
            int nc = c + d.second;

            if(nr < 0 || nc < 0 || nr >= row || 
            nc >= col || grid[nr][nc] != INT_MAX)
              continue;

            grid[nr][nc] = grid[r][c] + 1;

            q.push({nr, nc});
         }
       } 
    }
};
