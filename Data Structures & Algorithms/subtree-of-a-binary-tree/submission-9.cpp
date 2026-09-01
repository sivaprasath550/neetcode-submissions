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

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == nullptr) return true;

        if(root == nullptr) return false;
        
        if(root -> val == subRoot -> val){
            if(isSameTree(root, subRoot)) return true;
        }
        
        return isSubtree(root -> left, subRoot) ||
        isSubtree(root -> right, subRoot);
         
    }
};