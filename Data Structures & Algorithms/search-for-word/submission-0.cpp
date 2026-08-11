class Solution {
public:
    bool backTrack(int i, int j, vector<vector<char>> &board, 
    vector<vector<bool>> &vis, string& word, int index){

      if(index == word.size()) return true;

      if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
      || vis[i][j] || board[i][j] != word[index])
        return false;

      vis[i][j] = true;
      
      bool found =
            backTrack(i + 1, j, board, vis, word, index + 1) ||
            backTrack(i - 1, j, board, vis, word, index + 1) ||
            backTrack(i, j - 1, board, vis, word, index + 1) ||
            backTrack(i, j + 1, board, vis, word, index + 1);

      vis[i][j] = false;

      return found;
    }
   

    bool exist(vector<vector<char>>& board, string word) {
      int rows = board.size();
      int cols = board[0].size();

      vector<vector<bool>> vis(rows, vector<bool>(cols, false)); 

      for(int i = 0; i < rows; i++){
         for(int j = 0; j < cols; j++){
            if(backTrack(i, j, board, vis, word, 0))
            return true;
         }
      }
      return false;
    }
};
