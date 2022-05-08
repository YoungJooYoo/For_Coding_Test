class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        queue<TreeNode*> q;
        TreeNode* curr;
        vector<double> res;
        //vector<int> tmp;
        size_t len;
        
        q.push(root);
        
        while (q.size()) {
            //tmp.clear(); // bfs 탐색 중, 새로운 레벨로 되면 큐를 밀어서 다시 값을 채운다.
            vector<int> tmp;
            size_t len = q.size(); // bfs, 탐색 중, 탐색 레벨이 내려갈수록 노드의 갯수가 다르니, 사이즈를 다시 계산한다.
            for (size_t i = 0; i < len; i++) {
                curr = q.front();
                tmp.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                q.pop();
            }
            res.push_back(accumulate(begin(tmp), end(tmp), 0.0) / tmp.size());
        }
        
        return res;
    }
};