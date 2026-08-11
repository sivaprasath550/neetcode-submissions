class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> m1;
       vector<vector<string>> ans;

       for(int i = 0; i < strs.size(); i++){
          string s = strs[i];
          sort(s.begin(), s.end());
          m1[s].push_back(strs[i]);
       }
       for(auto it: m1){
          ans.push_back(it.second);
       }
       return ans; 
    }
};
