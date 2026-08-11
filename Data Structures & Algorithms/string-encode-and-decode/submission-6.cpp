class Solution {
public:

    string encode(vector<string>& strs) {
      string encoded_value = "";
      for(int i = 0; i < strs.size(); i++){
         string value = strs[i];
         int cnt = value.size();
         string strf = to_string(cnt);
         encoded_value.append(strf + "#" + value);
      }
      return encoded_value;
    }

    vector<string> decode(string s) {
      vector<string> ans;
      int i = 0;
      

   while (i < s.size()){

      string count = "";

      while(s[i] != '#'){
         count.push_back(s[i]);
         i++;
      }

      int len = stoi(count);

      i++;

      string curr = s.substr(i, len);
      ans.push_back(curr);      
      
      i += len;
     }
     return ans;
   }
};
