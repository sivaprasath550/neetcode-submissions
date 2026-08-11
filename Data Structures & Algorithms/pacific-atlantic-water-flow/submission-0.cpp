class Solution {

  int rows, cols;

private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>> &vis){
      vis[r][c] = true;

      vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

      for(auto d : dirs){
        int nr = r + d.first;
        int nc = c + d.second;

        if(nr < 0 || nc < 0 || nr >= rows || nc >= cols ||
         vis[nr][nc] || heights[nr][nc] < heights[r][c]){
          continue;
        }

        dfs(heights, nr, nc, vis);
      }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      rows = heights.size();
      cols = heights[0].size();

      vector<vector<int>> ans;

      vector<vector<bool>> pacAns(rows, vector<bool> (cols, false));
      vector<vector<bool>> atAns(rows, vector<bool> (cols, false));
      
      // Pacififc Boundary
      for(int r = 0; r < rows; r++){
        dfs(heights, r, 0, pacAns);
      }

      for(int c = 0; c < cols; c++){
        dfs(heights, 0, c, pacAns);
      }
      
      // Atlantic Boundary
      for(int r = 0; r < rows; r++){
        dfs(heights, r, cols - 1, atAns);
      }

      for(int c = 0; c < cols; c++){
        dfs(heights, rows - 1, c, atAns);
      }

      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
          if(pacAns[i][j] && atAns[i][j]){
            ans.push_back({i, j});
          }
        }
      }

      return ans;
    }
};
