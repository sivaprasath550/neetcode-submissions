class Solution {
public:

    void backTrack(vector<int>& nums, vector<int>& subSum,
                   vector<vector<int>>& ans, int target, int start) {

        if(target == 0) {
            ans.push_back(subSum);
            return;
        }

        if(target < 0) return;

        for(int i = start; i < nums.size(); i++) {

            subSum.push_back(nums[i]);

            backTrack(nums, subSum, ans, target - nums[i], i);

            subSum.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subSum;
        vector<vector<int>> ans;

        backTrack(nums, subSum, ans, target, 0);

        return ans;
    }
};
