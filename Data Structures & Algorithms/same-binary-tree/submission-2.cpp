class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both are empty
        if (p == nullptr && q == nullptr)
            return true;

        // One is empty, the other isn't
        if (p == nullptr || q == nullptr)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Check corresponding subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};