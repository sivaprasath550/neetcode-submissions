class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0;
        int right = n;

        int half = (n + m + 1) / 2;

        while(left <= right){

            int i = left + (right - left) / 2;
            int j = half - i;

            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n) ? INT_MAX : nums1[i];

            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == m) ? INT_MAX : nums2[j];

            if(left1 > right2){
                right = i - 1;
            }

            else if(left2 > right1){
                left = i + 1;
            }

            else{
                if((n + m) % 2 == 1){
                    return max(left1, left2);
                }
                
                else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
        }

        return 0.0;
    }
};
