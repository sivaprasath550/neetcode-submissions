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
int res = INT_MIN;

    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int left = max(0, dfs(root -> left));
        int right = max(0, dfs(root -> right));

        int subSum = root -> val + left + right;
        int nodeRes = root -> val + max(left, right);

        res = max(res, subSum);
        
        return nodeRes;
    }

    int maxPathSum(TreeNode* root) {
       dfs(root);
       return res;
    }
};
