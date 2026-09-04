class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int fresh = 0;

        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto [row, col] = q.front();
                q.pop();

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                for(int i = 0; i < 4; i++){
                    int nr = dr[i] + row;
                    int nc = dc[i] + col;

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                      grid[nr][nc] == 1){

                      grid[nr][nc] = 2;
                      fresh--;

                      q.push({nr, nc});
                    }
                }
            }
            
            ans++;
        }

        if(fresh > 0) return -1;

        return ans;  
    }
};
