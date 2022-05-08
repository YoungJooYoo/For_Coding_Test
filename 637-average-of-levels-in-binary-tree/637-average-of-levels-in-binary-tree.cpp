class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<double> res;
        TreeNode* curr;
        
        q.push(root);
        
        while (q.size() != 0) {
            vector<int> temp; // 노드의 값들을 저장하는 임시 장소, 이 배열의 값을 이용해 평균을 구한다.
            size_t len = q.size(); // bfs, 탐색 중, 탐색 레벨이 내려갈수록 노드의 갯수가 다르니, 사이즈를 다시 계산한다.
            for (size_t i = 0; i < len; i++) {
                curr = q.front(); q.pop();// 큐에 있는 노드를 빼온다.
                temp.push_back(curr->val); // temp 값들을 집어 넣는다.
                // 노드 하위에 있는 노드를 큐에 넣어서 bfs 탐색을 한다.
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            res.push_back(accumulate(begin(temp), end(temp), 0.0) / temp.size()); // 0.0은 초기 값
        }
        
        return res;
    }
};