class KthLargest {
public:
vector<int> nums;
int k;

    KthLargest(int k, vector<int>& nums) {
      this -> k = k;
      this -> nums = nums;  
    }
    
    int add(int val) {
      nums.push_back(val);

      sort(nums.begin(), nums.end(), greater<int>());

      if(nums.size() < k) return -1;
      
      return nums[k - 1];
    }
};
