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
    int dfs(TreeNode* root, int maxVal){
        int good = 0;

        if(root == NULL) return 0;
        if(root -> val >= maxVal) good++;

        maxVal = max(maxVal, root -> val);

        good += dfs(root -> left, maxVal);
        good += dfs(root -> right, maxVal);

        return good;
    }

    int goodNodes(TreeNode* root) {
      return dfs(root, INT_MIN);
    }
};
