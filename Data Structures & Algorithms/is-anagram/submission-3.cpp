class Solution {
public:
    bool isAnagram(string s, string t) {

      if(s.size() != t.size()) return false;
      unordered_map<char, int>m1;
      unordered_map<char, int>m2;

      for(int i = 0; i < s.size(); i++){
        m1[s[i]]++; 
    }
    for(int j = 0; j < t.size(); j++){
        m2[t[j]]++;
    }
    if(m1 == m2) return true;
    return false;
    }
};
