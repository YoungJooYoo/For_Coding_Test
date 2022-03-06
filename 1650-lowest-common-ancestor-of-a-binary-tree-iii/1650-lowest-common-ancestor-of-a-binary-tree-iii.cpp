class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
		// Check if any of p,q can be LCA.
        if(subtree(p, q) == true) {
            return p;
        }
        if(subtree(q, p) == true) {
            return q;
        }
        // It means LCA is in the upper tree.
        return upperTree(p->parent, p, q);
    }
    
    bool subtree(Node* root, Node * target) // 주어진 p, q인지 확인한다.
    {
        if (root == nullptr) {
            return false;
        }
        if (root == target)  {
            return true;
        }
        
        return subtree(root->left, target) || subtree(root->right, target);
    }
    
    Node* upperTree(Node* parent, Node* child, Node* target) 
    {
        if (parent->right == child && subtree(parent->left, target)) {
            return parent;
        }
        if (parent->left == child && subtree(parent->right, target)) {
            return parent;
        }
        
        return upperTree(parent->parent, parent, target);
    }
};