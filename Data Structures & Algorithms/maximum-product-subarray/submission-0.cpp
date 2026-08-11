class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int prevMin = nums[0];
       int prevMax = nums[0];
       int ans = nums[0];

       for(int i = 1; i < nums.size(); i++){
        
        int temp = prevMax;

        prevMax = max({nums[i],
                     nums[i] * prevMax, 
                     nums[i] * prevMin});

        prevMin = min({nums[i], 
                     nums[i] * temp, 
                     nums[i] * prevMin});

        ans = max(ans, prevMax); 
       }

       return ans;
    }
};
