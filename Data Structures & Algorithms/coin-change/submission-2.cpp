class Solution {
public:
    int solve(int amount, vector<int> &coins, vector<int> &dp){

        if(amount == 0) return 0;
        
        const int INF = 1e9;
        int ans = INF;

        if(amount < 0) return INF;

        if(dp[amount] != -1) return dp[amount];

        for(int i = 0; i < coins.size(); i++){
            int res = solve(amount - coins[i], coins, dp);

            if(res != -1) ans = min(ans, 1 + res);
        }
        
        dp[amount] = ans;

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
       
       vector<int> dp(amount + 1, -1);
       int result = solve(amount, coins, dp);

       if(result >= 1e9) return -1;
       return result;
       
    }
};
