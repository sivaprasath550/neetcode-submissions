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
    int dfs (TreeNode* curr, int maxi){
        if(curr == nullptr){
            return 0;
        }

        int good = 0;

        if(curr -> val >= maxi){
            good = 1;
        }
        
        maxi = max(maxi, curr -> val);
        
        int left = dfs(curr -> left, maxi);
        int right = dfs(curr -> right, maxi);

        return good + left + right;
    }

    int goodNodes(TreeNode* root) {
       return dfs(root, root -> val);
    }
};
