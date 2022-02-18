class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> node_list;
        node_list.push(root);
        
        while (node_list.empty() == false) {
            size_t list_size = node_list.size();
            vector<int> temp;
            while (list_size > 0) {
                list_size--;
                TreeNode* node = node_list.front();
                node_list.pop();
                temp.push_back(node->val);
                if (node->left != nullptr) {
                    node_list.push(node->left);
                }
                if (node->right != nullptr) {
                    node_list.push(node->right);
                }
            }
            result.push_back(temp);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

/* 
풀이해설 :

BFS, 순차적으로 탐색  큐를 생성, 큐에대 각 노드를 넣어가면서 순차적 탐색한다.
탐색하면서 node->val 값을 넣고,
최종적 탐색이 순차적으로 끝나면, reverse함수로 순차적 탐색 방향을 뒤집는다.

*/