class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int longest = 1;

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int cnt = 1; // start length from 1 (itself)

            while(true){
                bool found = false;

                for(int j = 0; j < n; j++){
                    if(nums[j] == num + 1){
                        num = num + 1;
                        cnt++;
                        found = true;
                        break;
                    }
                }

                if(!found) break;
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};

