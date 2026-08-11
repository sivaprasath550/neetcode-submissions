// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();

//         if(n > m) return false;

//         int freq1[26] = {0};
//         int freq2[26] = {0};
//         int left = 0;
//         int right = 0;

//         for(char c : s1){
//             freq1[c - 'a']++;
//         }
        
//         while(right < m){
//             freq2[s2[right] - 'a']++;
            
//             if(right - left + 1 > n){
//                 freq2[s2[left] - 'a']--;
//                 left++;
//             }

//             if(right - left + 1 == n){
//                 bool ifSame = true;
//                 for(int i = 0; i < 26; i++){
//                     if(freq1[i] != freq2[i]){
//                       ifSame = false;
//                       break;
//                     }
//                 }
//                 if(ifSame) return true;
//             }
//             right++;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int n = s1.size(), m = s2.size();

      if(n > m) return false;
      
      int freq1[26] = {0}, freq2[26] = {0};

      int left = 0, right = 0;

      for(char c : s1){
        freq1[c - 'a']++;
      }

      while(right < m){
        freq2[s2[right] - 'a']++;

        while(right - left + 1 > n){
          freq2[s2[left] - 'a']--;
          left++;
        }

        if(right - left + 1 == n){
          bool ifSame = true;
          for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
              ifSame = false;
              break;
            }
          }
          if(ifSame) return true;
        }
        right++;
      }
      return false;
    }
};
