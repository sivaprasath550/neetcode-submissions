class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      stack<pair<int, int>> st;
      int maxArea = 0;

      for(int i = 0; i < n; i++){
        int start = i;

        while(!st.empty() && heights[i] < st.top().second){
            int idx = st.top().first;
            int h = st.top().second;
            st.pop();

            int width = i - idx;
            int area = h * width;

            maxArea = max(maxArea, area);
            start = idx;
        }
        st.push({start, heights[i]});
      }

      while(!st.empty()){
        int idx = st.top().first;
        int h = st.top().second;
        st.pop();

        int width = n - idx;
        int area = h * width;

        maxArea = max(maxArea, area);
      }

      return maxArea;  
    }
};
