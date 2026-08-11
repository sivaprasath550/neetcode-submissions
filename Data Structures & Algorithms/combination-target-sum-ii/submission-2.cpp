class Solution {
public:
     void backTrack(vector<int>& candidates, vector<int>& subSum,
                   vector<vector<int>>& ans, int target, int start) {

        if(target == 0) {
            ans.push_back(subSum);
            return;
        }

        if(target < 0) return;


        for(int i = start; i < candidates.size(); i++) {
            
            if(i > start && candidates[i] == candidates[i - 1]) continue;

            subSum.push_back(candidates[i]);

            backTrack(candidates, subSum, ans, target - candidates[i], i + 1);

            subSum.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subSum;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        backTrack(candidates, subSum, ans, target, 0);

        return ans;
    }
};