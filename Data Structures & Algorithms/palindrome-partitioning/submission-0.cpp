class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;

            l++;
            r--;
        }

        return true;
    }

    void backTrack(string &s, vector<vector<string>> &ans, 
    vector<string> &part, int start){

        if(start == s.size()){
          ans.push_back(part); 
          return; 
        } 
        
        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s, start, end)){

                part.push_back(s.substr(start, end - start + 1));

                backTrack(s, ans, part, end + 1);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> part;
    
      int n = s.size();

      backTrack(s, ans, part, 0);

      return ans;
    }
};
