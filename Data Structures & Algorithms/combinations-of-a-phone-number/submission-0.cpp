class Solution {
public:

    void backTrack(unordered_map<int, string> &keypad,
    vector<string> &ans, string &digits, string &word, int index){

        if(index == digits.size()){
            ans.push_back(word);
            return;
        }

        int number = digits[index] - '0';
        string letters = keypad[number];

        for(int i = 0; i < letters.size(); i++){
            word.push_back(letters[i]);

            backTrack(keypad, ans, digits, word, index + 1);
            word.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
     if(digits.empty()) return {};

     unordered_map<int, string> keypad = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
     };
     vector<string> ans;
     string word = "";

     backTrack(keypad, ans, digits, word, 0);

     return ans;
    }
};