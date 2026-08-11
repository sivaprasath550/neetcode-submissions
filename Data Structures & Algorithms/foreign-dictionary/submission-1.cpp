class Solution {
public:
    string foreignDictionary(vector<string>& words) {
       unordered_map<char, vector<char>> graph;
       unordered_map<char, int> indegree;
       int n = words.size();

       for(string &word: words){
        for(char c: word){
            indegree[c] = 0;
        }
       }

       for(int i = 0; i < n - 1; i++){
        string w1 = words[i];
        string w2 = words[i + 1];

        if(w1.size() > w2.size() && 
        w1.substr(0, w2.size()) == w2)
          return "";

        int len = min(w1.size(), w2.size());

        for(int j = 0; j < len; j++){
            if(w1[j] != w2[j]){

                graph[w1[j]].push_back(w2[j]);
                indegree[w2[j]]++;
                break;
            }
        }
       }

       queue<char>q;
       for(auto& it: indegree){
        if(it.second == 0){
            q.push(it.first);
        }
       }

       string ans;

       while(!q.empty()){
        char cur = q.front();
        q.pop();
        
        ans += cur;

        for(char next: graph[cur]){
            indegree[next]--;

            if(indegree[next] == 0){
                q.push(next);
            }
        }
       }

       if(ans.size() != indegree.size()) 
           return "";
        
        return ans;
    }
};
