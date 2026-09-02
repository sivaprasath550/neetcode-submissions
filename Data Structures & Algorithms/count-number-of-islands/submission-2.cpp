class Solution {
public:
    int numIslands(vector<vector<char>>& grid){
        int i = 0;
        int j = 0;

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == '1' && !vis[i][j]){
                   
                   ans++;

                   queue<pair<int, int>> q;

                   q.push({i,j});
                   vis[i][j] = true;
 
                   while(!q.empty()){
                    auto word = q.front();
                    q.pop();

                    int ith = word.first;
                    int jth = word.second;
            
                    int dr[] = {0, -1, 0, 1};
                    int dc[] = {1, 0, -1, 0};

                    for(int i = 0; i < 4; i++){
                      int nr = ith + dr[i];
                      int nc = jth + dc[i];
               
                      if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                      && grid[nr][nc] != '0' && !vis[nr][nc]) {

                      q.push({nr, nc});
                      vis[nr][nc] = true;
                    }
                 }
              } 
            }
         }
      }
      return ans;
    }
};
