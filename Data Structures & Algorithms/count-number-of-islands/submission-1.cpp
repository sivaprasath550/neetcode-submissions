class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int cnt){

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
        || grid[i][j] == '0')
        return;

        if(grid[i][j] == '1'){
            grid[i][j] = '0';

            dfs(grid, i + 1, j, cnt);
            dfs(grid, i - 1, j, cnt);
            dfs(grid, i, j + 1, cnt);
            dfs(grid, i, j - 1, cnt);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
      int row = grid.size();
      int col = grid[0].size();
      int cnt = 0;

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){

            if(grid[i][j] == '1'){
                cnt++;
                dfs(grid, i, j, cnt);
            }
        }
      }

      return cnt;   
    }
};
