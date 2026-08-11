class WordDictionary {
private: 
    struct Node{
        Node* children[26];
        bool isEnd;

        Node(){
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            isEnd = false;
        }
    };
    Node* root;

    bool dfs(string &word, int pos, Node* node){

      if(pos == word.size()){
        return node -> isEnd;
      }

      char c = word[pos];

      if(c != '.'){
        int index = c - 'a';

        if(node -> children[index] == nullptr)
          return false;
        
        return dfs(word, pos + 1, node -> children[index]);
      }

        for(int i = 0; i < 26; i++){
          if(node -> children[i] != nullptr){

            if(dfs(word, pos + 1, node -> children[i]))
            return true;
          }
        }
      return false;
    }

public:
    WordDictionary() {
      root = new Node();  
    }
    
    void addWord(string word) {
      Node* curr = root;

      for(char c : word){
        int index = c - 'a';

        if(curr -> children[index] == nullptr){
            curr -> children[index] = new Node();
        }

        curr = curr -> children[index];
      }

      curr -> isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
