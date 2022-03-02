class Solution {
public:

    void BFS(TreeNode* root, map<int, vector<int>>& m)
    {
        if (root == nullptr) {
            return;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front(); q.pop();
            m[temp.second].push_back(temp.first->val);// put the current element into its group in the map
            
            auto tree_node = temp.first;
            auto value = temp.second;
            if(tree_node->left) {
                q.push({tree_node->left, value - 1}); // value - 1,  + 1하면서 찾아야할 값들을 짝을 지어준다. ex) root val = 3, value = 0,   root val = 15 그리고 value 0 서로 짝이다.
            }
            if(tree_node->right) {
                q.push({tree_node->right, value + 1});
            }
        }
        
        return;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        
        BFS(root, m);
        
        // map안에 저장된 배열을 순차적으로 ans 배열에 집어 넣는다.
        for (const auto& it : m) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};