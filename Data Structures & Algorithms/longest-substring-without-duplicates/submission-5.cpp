// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {

//         int n = s.size();
//         unordered_map<char, int>lastIndex;
//         int left = 0;
//         int right = 0;
//         int maxLen = 0;

//         while(right < n){
            
//             if(lastIndex.find(s[right]) != lastIndex.end() 
//             && lastIndex[s[right]] >= left){
//                 left = max(left, lastIndex[s[right]] + 1);
//             }

//             lastIndex[s[right]] = right;
//             maxLen = max(maxLen, right - left + 1);
//             right++;
//         }
//         return maxLen;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
      unordered_map<char, int> lastIndex;
      int left = 0, right = 0, maxLen = 0;
      
      while(right < n){
        if(lastIndex.find(s[right]) != lastIndex.end() && 
        lastIndex[s[right]] >= left){
          left = max(left, lastIndex[s[right]] + 1);
        }

        lastIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
        right++;
      }
      return maxLen;
    }
};
