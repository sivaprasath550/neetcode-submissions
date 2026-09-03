/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       
       if(root == nullptr){
        return ans;
       }

       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
        vector<int> subAns;
        int level = q.size();

        for(int i = 0; i < level; i++){

            TreeNode* first = q.front();
            q.pop();

            subAns.push_back(first -> val);

            if(first -> left != nullptr){
             q.push(first -> left);
            }

            if(first -> right != nullptr){
             q.push(first -> right);
            }
          }

          ans.push_back(subAns);
        } 

      return ans;
    }
};
