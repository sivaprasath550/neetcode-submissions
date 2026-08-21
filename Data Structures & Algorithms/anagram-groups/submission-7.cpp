class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
      vector<vector<string>> ans;
      unordered_map<string, vector<string>> anagrams;

      int n = strs.size();

      for(int i = 0; i < n; i++){

        string start = strs[i];
        sort(start.begin(), start.end());

        anagrams[start].push_back(strs[i]);
      }

      for(auto it : anagrams){
        ans.push_back(it.second);
      }

      return ans;
    }
};
