class Solution {
public:
    void pre_order(Node* root)
    {
        if (root == nullptr) {
            return;
        }
        
        ans.push_back(root->val);
        
        for (const auto& children_node : root->children)               
        {
            pre_order(children_node);
        }    
    }
    
    vector<int> preorder(Node* root) 
    {
        pre_order(root);
        return ans;
    } 
    
private:
    vector<int> ans;
};