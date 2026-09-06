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
    int preStart = 0;

    TreeNode* build(vector<int> &preorder, int low,  int high, 
    unordered_map<int, int> &inMap){

       if(low > high) return nullptr;

       int rootVal = preorder[preStart++];
       TreeNode* root = new TreeNode(rootVal);

       int index = inMap[rootVal];

       root -> left = build(preorder, low, index - 1, inMap);
       root -> right = build(preorder, index + 1, high, inMap);

       return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

       unordered_map<int, int> inMap;

       for(int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
       } 

       return build(preorder, 0, inorder.size() - 1, inMap);
    }
};
