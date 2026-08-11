class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
      int n = nums1.size();
      int m = nums2.size();

      int totNums = n + m;
      long long halfNums = (totNums + 1) / 2;

      int low = 0;
      int high = n;

      while(low <= high){
        int i = low + (high - low) / 2;
        
        int j = halfNums - i;

        int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
        int Aright = (i == n) ? INT_MAX : nums1[i];
        int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
        int Bright = (j == m) ? INT_MAX : nums2[j];

        if(Aleft <= Bright && Bleft <= Aright){
          if(totNums % 2 == 1){
            return max(Aleft, Bleft);
          }
          else{
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
          }  
        }

        else if (Aleft > Bright) {
            high = i - 1;
        }

        else{
            low = i + 1;
        }        
      }
      return 0.0; 
    }
};
