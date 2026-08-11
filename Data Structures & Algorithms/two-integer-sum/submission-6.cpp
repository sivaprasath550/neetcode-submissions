class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();
      unordered_map<int, int> check;
      
      for(int i = 0;  i < n; i++){
        int need = target - nums[i];
        auto it = check.find(need);

        if(it != check.end()){
          return {it->second, i};
        }

        check[nums[i]] = i;
      }
      
      return {};
   }
};
