class Solution {
int rows, cols;

private:
    void dfs(vector<vector<char>>& board, int r, int c){

        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O')
          return;
        
        board[r][c] = '#';
        
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(auto d : dirs){
            int nr = r + d.first;
            int nc = c + d.second;

            dfs(board, nr, nc);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
       rows = board.size();
       cols = board[0].size();

       for(int r = 0; r < rows; r++){
        if(board[r][0] == 'O') dfs(board, r, 0);
        if(board[r][cols - 1]) dfs(board, r, cols - 1);
       }

       for(int c = 0; c < cols; c++){
        if(board[0][c] == 'O') dfs(board, 0, c);
        if(board[rows - 1][c] == 'O') dfs(board, rows - 1, c);
       }

       for(int i = 0 ; i < rows; i++){
        for(int j = 0; j < cols; j++){

            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }

            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }
        }
       }
    }
};
