class BSTIterator {
public:
    BSTIterator(TreeNode* root) 
    {
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
    vector<int> nums;
    size_t i = 0;
};

/*
풀이법 :
트리를 순회한다. 문제에서는 중위순회로 dfs 탐색을 하고
탐색한 값들을 배열에 전부 넣어둔다.
배열의 인덱스로 접근해서, 순서에 맞게 반환한다.

특히 배열의 인덱스가 넘어가는 것을 트리의 끝으로 보고 반환 값을 false로 한다.

*/