class Solution {
public:

    vector<vector<string>> ans;

    void backTrack(int row,
                   vector<string> &board,
                   vector<int> &sameCol,
                   vector<int> &leftDia,
                   vector<int> &rightDia,
                   int n) {

        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){

            if(sameCol[col] == 0 &&
               leftDia[row - col + (n-1)] == 0 &&
               rightDia[row + col] == 0){

                board[row][col] = 'Q';
                sameCol[col] = 1;
                leftDia[row - col + (n-1)] = 1;
                rightDia[row + col] = 1;

                backTrack(row + 1, board, sameCol, leftDia, rightDia, n);

                board[row][col] = '.';
                sameCol[col] = 0;
                leftDia[row - col + (n-1)] = 0;
                rightDia[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<int> sameCol(n, 0);
        vector<int> leftDia(2*n - 1, 0);
        vector<int> rightDia(2*n - 1, 0);

        backTrack(0, board, sameCol, leftDia, rightDia, n);

        return ans;
    }
};
