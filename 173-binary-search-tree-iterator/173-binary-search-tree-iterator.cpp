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
        if (i < nums.size()) { // 배열의 마지막이 넘어가면 flase다. 노드 끝으로 간주
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