class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
        || grid[i][j] == 0)
        return 0;

        grid[i][j] = 0;

        int area = 1;

        area += dfs(grid, i + 1, j);
        area += dfs(grid, i - 1, j);
        area += dfs(grid, i, j + 1);
        area += dfs(grid, i, j - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int row = grid.size();
      int col = grid[0].size();
      int maxi = 0;

      if(row == 0 && col == 0) return 0;

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){

            if(grid[i][j] == 1){
                int area = dfs(grid, i, j);
                maxi = max(maxi, area);
            }
        }
      }

      return maxi;   
    }
};

