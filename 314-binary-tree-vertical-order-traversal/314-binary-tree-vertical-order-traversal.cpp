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
            
            if(temp.first->left) {
                q.push({temp.first->left, temp.second - 1});
            }
            if(temp.first->right) {
                q.push({temp.first->right, temp.second + 1});
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