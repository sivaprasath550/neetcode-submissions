class Solution {
public:
    void backTrack(int n, vector<string> &ans, string s, int open_used, int close_used){
       
       if(s.size() == 2*n){
        ans.push_back(s);
        return;
       }

       if(open_used < n){
        s.push_back('(');
        backTrack(n, ans, s, open_used + 1, close_used);
        s.pop_back();
       }

       if(close_used < open_used){
        s.push_back(')');
        backTrack(n, ans, s, open_used, close_used + 1); 
        s.pop_back();
       } 
    }

    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string s = "";

       backTrack(n, ans, s, 0, 0);
       return ans; 
    }
};
