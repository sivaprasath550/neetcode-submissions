// class Solution {
// public:
//     int solve(int i, int target, vector<int> &nums){
//         int n = nums.size();

//         if(i == n) 
//           return target == 0;
        
//         int plus = solve(i + 1, target - nums[i], nums);
//         int minus = solve(i + 1, target + nums[i], nums);

//         return plus + minus;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//        return solve(0, target, nums); 
//     }
// };

class Solution {
public:

int solve(int i, int target,
          vector<int>& nums,
          vector<vector<int>>& dp) {

    if(i == nums.size())
        return target == 0;

    if(dp[i][target] != -1)
        return dp[i][target];

    int take = 0;

    if(nums[i] <= target)
        take = solve(i + 1,
                     target - nums[i],
                     nums,
                     dp);

    int skip = solve(i + 1,
                     target,
                     nums,
                     dp);

    return dp[i][target] = take + skip;
}

int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        // Impossible cases
        if(abs(target) > totalSum)
            return 0;

        if((totalSum + target) % 2 != 0)
            return 0;

        int subsetSum = (totalSum + target) / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(subsetSum + 1, -1)
        );

        return solve(0, subsetSum, nums, dp);
    }
};