class Solution {
public:
    bool solve(int i, int target, vector<int> &nums, vector<bool> &dp){
        if(target == 0) return true;

        if(i == nums.size()) return false;

        if(dp[i]) return true;

        bool take = false;

        if(nums[i] <= target){
           take = solve(i + 1, target - nums[i], nums, dp); 
        }

        bool skip = solve(i + 1, target, nums, dp);

        return dp[i] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
       vector<bool> dp(nums.size(), false);
       int sum = 0;

       for(int num : nums){
          sum += num;
       }

       if(sum % 2 != 0) return false;

       int target = sum / 2;

       return solve(0, target, nums, dp); 
    }
};
