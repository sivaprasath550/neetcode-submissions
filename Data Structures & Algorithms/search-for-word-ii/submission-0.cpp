class Solution {
private: 
    struct Node{
        Node* children[26];
        string word;

        Node(){
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };
    
    Node* root;
    vector<string> ans;

    void dfs(int i, int j, vector<vector<char>> &board, Node* node){
      char c = board[i][j];

      if(c == '#' || node -> children[c - 'a'] == nullptr){
        return;
      }
      node = node -> children[c - 'a'];

      if(node -> word != ""){
        ans.push_back(node -> word);
        node -> word = "";
      }

      board[i][j] = '#';

      int rows = board.size();
      int cols = board[0].size();

      if (i > 0) dfs(i - 1, j, board, node);
      if (j > 0) dfs(i, j - 1, board, node);
      if (i < rows - 1) dfs(i + 1, j, board, node);
      if (j < cols - 1) dfs(i, j + 1, board, node);

      board[i][j] = c;
    }


void addWords(string &word){

  Node* curr = root;
  for(char c : word){

  int index = c - 'a';

  if(curr -> children[index] == nullptr){
    curr -> children[index] = new Node();
  }

  curr = curr -> children[index];
  }

 curr -> word = word; 
}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      root = new Node();

      for(auto &w : words){
        addWords(w);
      }
      
      if(board.empty() || board[0].empty()) return {};
      
      int rows = board.size();
      int cols = board[0].size();

      for(int i = 0; i < rows; i++){
         for(int j = 0; j < cols; j++){
            dfs(i, j, board, root);
         }
      }
      return ans;
    }
};
