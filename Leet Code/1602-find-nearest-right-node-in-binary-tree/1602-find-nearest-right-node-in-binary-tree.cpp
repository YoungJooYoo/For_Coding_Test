class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) 
    {
        if (root == nullptr) {
            return NULL;
        }
        queue<TreeNode*> node_list; // 큐를 사용해 탐색할 노드들을 넣는다.
        node_list.push(root);
        
        // BFS
        while (node_list.empty() == false) {
            size_t node_list_size = node_list.size(); // 큐에서 탐색해야할 노드 갯수 구하기
            
            while (node_list_size > 0) { // 탐색할 큐가 남았다면, 이 노드가 가진 하위 노드들을 검색해서 탐색 list에 넣기
                node_list_size--;
                TreeNode* node = node_list.front(); // 큐에 들어온 순서대로 탐색 시작
                node_list.pop();
                
                if (node == u) { // 타겟 값이 나오면, 그 값의 오른쪽을 반환
                    TreeNode* right_node = node_list.front();
                    
                    if (node_list_size == 0) { // 우측에 더 이상 노드가 없을때
                        return NULL;
                    }
                    else { // 큐에 노드가 남아 있다면, 오른쪽 노드를 반환한다.
                        return right_node;
                    }
                }
                if(node->left != nullptr) { // 다음 깊의의 탐색할 노드를 넣어줌
                    node_list.push(node->left);
                }
                if(node->right != nullptr) {
                    node_list.push(node->right);
                }
            }
        }
        
        return NULL;
    }
};

/*
풀이법 : BFS

같은 레벨에서 둘이 가장 가까운 노드를 찾는다.
노드는 오른쪽이다
BFS로 풀이하면 된다.
핵심은 오른쪽 노드, 오른쪽 노드는 BFS에서 다음 노드를 의미
BFS 큐에서 다음 노드가 있다면 그것을 반환
다음 노드가 없다면 NULL반환

*/