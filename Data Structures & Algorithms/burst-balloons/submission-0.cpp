class Solution {
public:
    int solve(int left, int right, vector<int> &nums, vector<vector<int>> &dp){

        if(left+1 == right){
            return 0;
        }

        if(dp[left][right] != -1) return dp[left][right];
        
        int ans = 0;

        for(int k = left+1; k < right; k++){
            
            int coins = solve(left, k, nums, dp) 
            +
            solve(k, right, nums, dp)
            +
            nums[left] * nums[k] * nums[right];

            ans = max(ans, coins);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {
      
      vector<int> arr;

      arr.push_back(1);

      for(int num : nums){
        arr.push_back(num);
      }

      arr.push_back(1);

      int n = arr.size();

      vector<vector<int>> dp(
        n, vector<int>(n, -1)
      );

      return solve(0, n - 1, arr, dp) ;

    }
};
