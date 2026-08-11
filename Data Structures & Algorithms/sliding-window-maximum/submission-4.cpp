class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> maxAns;
      int left = 0;
      int right = 0;
      deque<int> dq;

      while(right < n){

        while(!dq.empty() && nums[dq.back()] < nums[right]){
            dq.pop_back();
        }

        dq.push_back(right);

        if(!dq.empty() && dq.front() < left){
            dq.pop_front();
        }
        
        if(right - left + 1 == k){
            maxAns.push_back(nums[dq.front()]);
            left++;
        }
        right++;
      }
      return maxAns; 
    }
};
