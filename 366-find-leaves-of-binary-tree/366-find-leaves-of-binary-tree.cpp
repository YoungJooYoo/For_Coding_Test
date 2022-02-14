class Solution {
public:
    bool isLeaf(TreeNode* root){
        return (root->left == nullptr && root->right == nullptr) ? true : false;
    }
    
    TreeNode* dfs(TreeNode* root) 
    {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (isLeaf(root)) {
            temp.push_back(root->val);
            return nullptr;
        }
        
        // dfs 시행할따마다 leaf는 nullptr이 되어 삭제가 된다.
        // 즉 while 한번씩 돌떄마다, 문제에서 제시한 모양의 트리로 바뀌어간다.
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        
        return root;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        while (root != nullptr) {
            root = dfs(root); // 최종적으로 트리의 시작점 즉 root도 null로 만들어 탐색을 끝낸다.
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    vector<int> temp;
    
};

/*
풀이법 :
방문한 트리를 제거하고,
dfs를 다시 반복해서 시행함으로
방문을 도출한다.
*/