// class Solution {
// public:
//     int characterReplacement(string s, int k) {

//       int n = s.size();
//       int maxFreq = 0;
//       int maxLen = 0;
//       int left = 0;
//       int right = 0;
//       unordered_map<char, int> freq; 

//       while(right < n){

//         freq[s[right]]++;
//         maxFreq = max(maxFreq, freq[s[right]]);
           

//         while((right - left + 1) - maxFreq > k){
//            freq[s[left]]--;
//            left++;
//         }

//         maxLen = max(maxLen, right - left + 1);
//         right++;
            
//       }
//       return maxLen; 
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
      int n = s.size();
      int left = 0, right = 0;
      int maxLen = 0, maxFreq = 0;
      unordered_map<char, int>freq;

      while(right < n){
        freq[s[right]]++;
        maxFreq = max(maxFreq, freq[s[right]]);

        while((right - left + 1) - maxFreq > k){
          freq[s[left]]--;
          left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
      }
      return maxLen;
    }
};

