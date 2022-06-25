class Solution {
public:
    void func(TreeNode* root)
    {
        if (root == NULL) {
            return ;
        }
        if (root->left) {
            mp[root->left] = root;
            func(root->left);
        }
        if (root->right) {
            mp[root->right] = root;
            func(root->right);
        }
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        queue<TreeNode*> q;
        unordered_set<int> st;  // 방문체크
        int level = 0; // at level == k , all the nodes in queue is our required nodes
        vector<int> ans;
        
        st.insert(target->val); // 방문했던 노드의 값을 넣는다.
        q.push(target); // bfs 큐에 넣는다.
        func(root); // 재귀함수로, 자식-부모 해시를 구한다.
        
        while (!q.empty()) { // BFS 탐색
            int size = q.size();
            while (size--) { // 큐 사이즈만큼 퓨를 비워가면서 탐색
                if (level == k) {
                    while (!q.empty()) {
                        ans.push_back(q.front()->val);
                        q.pop();
                    }
                    return ans;
                }
                
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr->left != nullptr && st.find(curr->left->val) == st.end()) {
                    q.push(curr->left);
                    st.insert(curr->left->val); // 방문표시
                }
                if (curr->right != nullptr && st.find(curr->right->val) == st.end()) {
                    q.push(curr->right);
                    st.insert(curr->right->val); // 방문표시
                }
                if (mp[curr] && st.find(mp[curr]->val) == st.end()) {
                    q.push(mp[curr]); // curr의 부모 노드 넣는다.
                    st.insert(mp[curr]->val); // 방문표시
                }
                
            }
            level++; // 방문 깊이 증가
        }
        
        return ans;   
    }
    
private:
    unordered_map<TreeNode*, TreeNode*> mp; // 자식-부모 노드 매잉
};