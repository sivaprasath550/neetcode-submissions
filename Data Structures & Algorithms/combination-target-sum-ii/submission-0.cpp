class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& curr, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, curr, result);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, result);
        return result;
    }
};