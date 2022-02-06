class BSTIterator {
public:
    BSTIterator(TreeNode* root) 
    {
        curr = root;
        dfs(root);
    }
    
    int next() 
    {
        return nums[i++];
    }
    
    bool hasNext() 
    {
        // 노드가 한칸씩 이동하게 만들어야한다.
    
        if (i < nums.size()) {
            return true;
        }
        else {
            return false;
        }
        
        return false;
    }
    
    void dfs(TreeNode* root) 
    {
        if (root == nullptr) {
            return;
        }    
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
     
private:
    TreeNode* curr;
    vector<int> nums;
    size_t i = 0;
};