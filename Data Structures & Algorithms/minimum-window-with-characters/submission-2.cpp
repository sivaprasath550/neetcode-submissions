class Solution {
public:
    string minWindow(string s, string t) {
     int n = s.size();
     int m = t.size();
     vector<string> ans;
     
     if(m > n) return "";

     unordered_map<char, int>need;
     
     for(int i = 0; i < m; i++){
        need[t[i]]++;
     }

     int required = need.size();
     int left = 0;
     int right = 0;
     int formed = 0;

     unordered_map<char, int> window;
     int bestLen = INT_MAX;
     int bestStart = 0;

     while(right < n){
       window[s[right]]++;

       if(need.count(s[right]) && 
       window[s[right]] == need[s[right]]) formed++;

       while(formed == required){

        int len = right - left + 1;

        if(len < bestLen){
            bestLen = len;
            bestStart = left;
        }

        window[s[left]]--;

        if(need.count(s[left]) && window[s[left]] < need[s[left]]){
         formed--;
        }
        left++;
       }
       right++;
     }
     return (bestLen == INT_MAX) ? "" : s.substr(bestStart, bestLen);
    }
};
