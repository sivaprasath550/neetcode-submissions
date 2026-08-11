class Solution {
public:
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans, 1 + dfs(ni, nj, matrix, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};