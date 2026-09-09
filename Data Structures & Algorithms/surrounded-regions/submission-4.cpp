class Solution {
public:
    int n, m;

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board){

        if(vis[row][col] != 0)
          return;
        
        vis[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
           
            if(nr < 0 || nr >= n || nc < 0 || nc >= m )
              continue;

            if(board[nr][nc] == 'O' && vis[nr][nc] == 0){
                dfs(nr, nc, vis, board);
            }       
        } 
    }

    void solve(vector<vector<char>>& board) {
       n = board.size();
       m = board[0].size();

       vector<vector<int>> vis(n, vector<int>(m, 0));

       // check for O's in the boundary

       for(int j = 0; j < m; j++){

         if(board[0][j] == 'O'){
            dfs(0, j, vis, board);
         }
       }

       for(int i = 0; i < n; i++){

        if(board[i][0] == 'O'){
            dfs(i, 0, vis, board);
        }
       }

       for(int j = 0; j < m; j++){

        if(board[n - 1][j] == 'O'){
            dfs(n - 1, j, vis, board);
        }
       }

       for(int i = 0; i < n; i++){

        if(board[i][m - 1] == 'O'){
            dfs(i , m - 1, vis, board);
        }
       }

       // Now check against vis

       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(board[i][j] == 'O' && vis[i][j] == 0){
                board[i][j] = 'X';
            }
        }
       } 
    }
};
