class Solution {
public:

    int height(TreeNode* node) {

        // Empty tree is balanced and has height 0
        if (node == nullptr)
            return 0;

        // Get left subtree height
        int leftHeight = height(node->left);

        // If left subtree is unbalanced
        if (leftHeight == -1)
            return -1;

        // Get right subtree height
        int rightHeight = height(node->right);

        // If right subtree is unbalanced
        if (rightHeight == -1)
            return -1;

        // Check current node
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }
};