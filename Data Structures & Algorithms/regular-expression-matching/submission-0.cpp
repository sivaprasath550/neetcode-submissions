class Solution {
public:
    bool solve(int i, int j, string s, string p, vector<vector<int>> &dp){

        if(j == p.size()) 
          return dp[i][j] = (i == s.size());
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        bool firstMatch = (i < s.size() && 
                          (s[i] == p[j] || p[j] == '.'));
        
        if(j + 1 < p.size() && p[j + 1] == '*'){

            return dp[i][j] = solve(i, j + 2, s, p, dp) ||
                   (firstMatch && solve(i + 1, j, s, p, dp));
        }
        else{
            return dp[i][j] = firstMatch && 
                   solve(i + 1, j + 1, s, p, dp);
        }
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        
        vector<vector<int>>dp(
        n+1, vector<int>(m+1, -1)
        );

        return solve(0, 0, s, p, dp); 
    }
};