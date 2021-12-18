class Solution {
public:
    vector<string> ans;
    
    void dfs(TreeNode* root, string str)
    {
        TreeNode* node = root;    
        if(node == NULL) {
            return;
        }
        
        // 노드의 양쪽 끝이 NULL인 경우 끝단 node, 이 노드는 val만 넣기
        if(node->left == NULL && node->right == NULL) {
            ans.push_back(str + to_string(node->val));
        }
        
        //val + -> 기호 같이 넣기
        dfs(node->left, str + to_string(node->val) + "->");
        dfs(node->right, str + to_string(node->val) + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode* node = root;
        
        dfs(node, "");
        return ans;
    }
};

