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
    bool dfs(TreeNode* curr, long long low, long long high){
        if(curr == nullptr){
            return true;
        }

        if(curr -> val <= low || curr -> val >= high){
            return false;
        }

        return dfs(curr -> left, low, curr -> val) &&
               dfs(curr -> right, curr -> val, high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
