class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int, int>> q;

      int row = grid.size();
      int col = grid[0].size();

      int fresh = 0;
      int minTime = 0;

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 2)
              q.push({i, j});

            else if(grid[i][j] == 1)
              fresh++;
          } 
        }

       if(fresh == 0) return 0;
         
       vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

       while(!q.empty() && fresh > 0){
          int size = q.size();

         for(int i = 0; i < size; i++){
            auto [r, c] = q.front();
            q.pop();

            for(auto d : dirs){
              int nr = r + d.first;
              int nc = c + d.second;

              if(nr < 0 || nc < 0 || nr >= row || 
              nc >= col || grid[nr][nc] != 1)
               continue; 
              
              if(grid[nr][nc] == 1){
                grid[nr][nc] = 2;
                fresh--;

                q.push({nr, nc});
              }
              
            }
          }

        minTime++;
    }
    return (fresh == 0) ? minTime : -1;
  }
};
