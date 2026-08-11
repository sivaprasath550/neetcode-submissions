class Solution {
public:
    bool isValid(string s) {
      int n = s.size();
      stack<char> st;

      unordered_map<char, char> match = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};
      int i = 0;

      while(i < n){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
           if (st.empty()) return false;
           if (st.top() != match[s[i]]) return false;
           st.pop();
        }
         i++;
      }
      return st.empty();  
    }
};
