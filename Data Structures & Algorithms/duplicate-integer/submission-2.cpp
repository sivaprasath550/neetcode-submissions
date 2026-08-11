class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      set<int> s1;
      for(int i = 0; i < nums.size(); i++){
       s1.insert(nums[i]);
      }
      if(s1.size() == nums.size()) return false;
      return true; 
    }
};