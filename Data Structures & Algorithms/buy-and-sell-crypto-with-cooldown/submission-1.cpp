class Solution {
public:
    int solve(int i, bool canBuy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();

        if(i >= n) return 0;

        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy){

            int buy = -prices[i] + solve(i + 1, false, prices, dp);
            int skip = solve(i + 1, true, prices, dp);
            
            return dp[i][canBuy] = max(buy, skip);
        }

        else{
            
            int sell = prices[i] + solve(i + 2, true, prices, dp);
            int hold = solve(i + 1, false, prices, dp);

            return dp[i][canBuy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       
       vector<vector<int>>dp(n, vector<int>(2, -1));
       return solve(0, true, prices, dp); 
    }
};
