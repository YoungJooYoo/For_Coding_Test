class Solution {
public:    
    void findParent(TreeNode* node)
    {
        if (!node) {
            return;
        }
        if (node->left) {
            parent[node->left] = node;
            findParent(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            findParent(node->right);
        }
    }

    void dfs( TreeNode* node, int K) 
    {
        if (visit.find(node) != visit.end())  { // 존재하지 않는 곳 방문 x
            return; // node가 존재하지 않으면, 리턴 방문할 필요 없는 장소
        }
        
        visit.insert(node); // 방문 표시
        
        if (K == 0) { // K = 0; 상대 위치 k를 깍아 내리면서, 해당 노드 위치로 상대 위치 구해서, 결국 0이 되면 탐색종료
            ans.push_back(node->val);
            return;
        }
        if (node->left != nullptr) { // 자식 노드들 탐색
            dfs(node->left, K - 1);
        }
        if (node->right != nullptr) {
            dfs(node->right, K - 1);
        }
        
        TreeNode* p = parent[node]; // parent 노드
        
        // 부모 노드로 올라가서 탐색 방문체크가 되어 있으니 중복 방문 존재 x
        if (p != nullptr) {
            dfs(p, K - 1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        if (root == nullptr) {
            return ans;
        }
        findParent(root); // 해시에 자식-부모 노드 관계 만들어 두기
        dfs(target, K);
        
        return ans;
    }
    
private:
    vector<int> ans;   
    map<TreeNode*, TreeNode*> parent;  // son=>parent  매핑
    set<TreeNode*> visit;    // 유니크한 val 값으로 방문체크
};