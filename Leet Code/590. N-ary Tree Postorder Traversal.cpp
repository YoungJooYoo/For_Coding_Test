class Solution {
public:
    void traverse(const Node* root, vector<int>& post) const 
    {
        if (root == nullptr) {
            return;
        }

        for (const auto& child : root->children) {
            traverse(child, post);
        }
        post.push_back(root->val);
    }
    
    vector<int> postorder(const Node* root) const 
    {
        vector<int> post;
        traverse(root, post);

        return post;
    }
};

// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
