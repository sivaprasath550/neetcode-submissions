class Solution {
public:

    // Checks whether two trees are exactly the same
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == nullptr)
            return true;

        if (root == nullptr)
            return false;

        // If values match, check whether the trees are identical
        if (root->val == subRoot->val) {
            if (isSameTree(root, subRoot))
                return true;
        }

        // Search in left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};