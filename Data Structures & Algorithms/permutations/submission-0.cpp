class Solution {
public:
    void backTrack(vector<int>& nums, vector<vector<int>> &ans, vector<int> &subSet, vector<bool> &vis){
        
        if(subSet.size() == nums.size()){
            ans.push_back(subSet);
            return;
        }


        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;

            subSet.push_back(nums[i]);
            vis[i] = true;

            backTrack(nums, ans, subSet, vis);

            vis[i] = false;
            subSet.pop_back(); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> subSet;
       vector<vector<int>> ans;
       vector<bool> vis(nums.size(), false);

       backTrack(nums, ans, subSet, vis);
       return ans;
    }
};
