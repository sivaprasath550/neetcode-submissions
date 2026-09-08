class Solution {
public:
    
    int n, m;

    void bfs(vector<vector<int>>& heights,
    queue<pair<int, int>> &q,
    vector<vector<bool>> &visited){

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int i = 0; i < 4; i++){
                
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                  continue;

                if(visited[nr][nc])
                  continue;
                
                if(heights[nr][nc] < heights[r][c])
                  continue;
                
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        // Pacific 

        for(int i = 0; i < n; i++){
            pacific[i][0] = true;
            pq.push({i, 0});
        }

        for(int j = 0; j < m; j++){
            pacific[0][j] = true;
            pq.push({0, j});
        }

        // Atlantic

        for(int i = 0; i < n; i++){
            atlantic[i][m - 1] = true;
            aq.push({i, m - 1});
        }

        for(int j = 0; j < m; j++){
            atlantic[n - 1][j] = true;
            aq.push({n - 1, j});
        }

        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
