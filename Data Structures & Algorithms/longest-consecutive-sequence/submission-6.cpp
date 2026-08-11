class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> check(n);
        for(int i = 0; i < n; i++){
           check.insert(nums[i]);
        }
        
        int longest = 0;
        for(auto it: check){
            if(check.find(it - 1) == check.end()){
                int cnt = 1;
                int curr = it;
            while(check.find(curr + 1) != check.end()){
                cnt++;
                curr++;
            }
            longest = max(longest, cnt);
            }
        }
      return longest;
    }
};

