class Solution 
{
public:
    void dfsLeft(TreeNode* node, vector<int>& ans)
    {
        if(node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return;
        }
        
        ans.push_back(node->val);
        
        if (node->left != nullptr) {
            dfsLeft(node->left, ans);    
        } 
        else {
            dfsLeft(node->right, ans);
        }
    }
    
    void dfsRight(TreeNode* node, vector<int>& ans)
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return;
        }
        if(node->right != nullptr) {
            dfsRight(node->right, ans);    
        } 
        else {
            dfsRight(node->left, ans);
        }
        ans.push_back(node->val);
    }
    
    void dfsLeaves(TreeNode* node, vector<int>& ans)
    {
        if (node == nullptr){
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(node->val);
            return;
        }
        
        dfsLeaves(node->left, ans);
        dfsLeaves(node->right, ans);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) 
    {
        vector<int> ans;
        ans.push_back(root->val);
        
        dfsLeft(root->left, ans); // 트리 왼쪽 내부
        dfsLeaves(root->left, ans); // 트리 왼쪽 외각
        dfsLeaves(root->right, ans); // 트리 오른쪽 외각
        dfsRight(root->right, ans); // 트리 오른쪽 내각
        
        return ans;
    }
};