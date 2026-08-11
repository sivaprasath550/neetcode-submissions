class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      int n = tokens.size();
      int i = 0;
      stack<int> st;

      while(i < n){
        string tok = tokens[i];

        if(tok == "+" || tok == "-" || tok == "*" || tok == "/"){
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if(tok == "+") st.push(a + b);
            else if(tok == "-") st.push(a - b);
            else if(tok == "/") st.push(a / b);
            else st.push(a * b);
        }
        else{
            st.push(stoi(tok));
        }
        i++;
      }
      return st.top();   
    }
};