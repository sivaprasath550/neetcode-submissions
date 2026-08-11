class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> wordSet(wordList.begin(), wordList.end());

       if(wordSet.find(endWord) == wordSet.end()) 
       return 0;

       queue<pair<string, int>> q;
       unordered_set<string> vis;

       q.push({beginWord, 1});
       vis.insert(beginWord);

       while(!q.empty()){
        auto [word, count] = q.front();
        q.pop();

        for(int i = 0; i < word.size(); i++){
            string newWord = word;
            for(char c = 'a'; c <= 'z'; c++){
                newWord[i] = c;

                if(newWord == endWord){
                    return count + 1;
                } 

                if(wordSet.count(newWord) && !vis.count(newWord)){
                    vis.insert(newWord);
                    q.push({newWord, count + 1});
                }

                newWord[i] = word[i];
            }
        }
    }
    return 0;
   }
};
