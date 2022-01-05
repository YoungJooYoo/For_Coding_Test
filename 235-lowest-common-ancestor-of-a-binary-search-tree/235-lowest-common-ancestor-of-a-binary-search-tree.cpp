class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val) { // root가 p거나 q라면
            return root;
        }
        if(root->val < max(p->val, q->val) && root->val > min(p->val, q->val)) { 
            return root;
        }
        else if (root->val > max(p->val, q->val)) { // both are less than root then lca is left side
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};