class Solution {
public:
     void backTrack(vector<int>& nums,vector<int>& subSet,
      vector<vector<int>>& ans, int start){

        ans.push_back(subSet);

        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]) continue;

            subSet.push_back(nums[i]);

            backTrack(nums, subSet, ans, i + 1);

            subSet.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> subSet;
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());

      backTrack(nums, subSet, ans, 0);  

      return ans;
    }
};
