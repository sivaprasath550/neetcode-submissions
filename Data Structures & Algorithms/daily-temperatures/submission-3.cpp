class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      int i = 0;

      stack<int> st;
      vector<int> ans(n, 0);

      while(i < n){
        while(!st.empty() && temperatures[i] > temperatures[st.top()]){
            int prev = st.top();
            st.pop();
            ans[prev] = i - prev;
        }
        
        st.push(i);
        i++;
      }
      return ans;
    }
};
