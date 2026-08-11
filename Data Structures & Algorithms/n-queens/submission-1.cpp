class Solution {
public:
    
    void backTrack(int row, vector<vector<string>> &ans, vector<string> &board, 
    vector<int> &sameCol, vector<int> &leftDia, vector<int> &rightDia, int n){

        if(row == n){
          ans.push_back(board);
          return;
        }

        for(int col = 0; col < n; col++){

          if(sameCol[col] == 0 && leftDia[row - col + (n - 1)] == 0 &&
          rightDia[row + col] == 0){

                board[row][col] = 'Q';
                sameCol[col] = 1;
                leftDia[row - col + (n - 1)] = 1;
                rightDia[row + col] = 1;

                backTrack(row + 1, ans, board, sameCol, leftDia, rightDia, n);

                board[row][col] = '.';
                sameCol[col] = 0;
                leftDia[row - col + (n - 1)] = 0;
                rightDia[row + col] = 0;
          }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n, string(n, '.'));

      vector<int> sameCol(n, 0), leftDia(2*n - 1, 0), rightDia(2*n - 1, 0);

      backTrack(0, ans, board, sameCol, leftDia, rightDia, n);

      return ans;  
    }
};
