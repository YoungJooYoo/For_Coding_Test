class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* curr = root;
        TreeNode* prev; // curr 직전의 node를 저장
        
        if (root == nullptr) {
            root = new TreeNode;
            root->val = val;
            return root;
        }
        
        while (curr != nullptr) {
            prev = curr; // curr이 탐색 마지막 가면 null이 되므로, null 이전에 새 노드를 추가할 노드위치 기억
            if (val < curr->val) { // 왼쪽탐색
                curr = curr->left;
            }
            else { // val > curr->val 오른쪽탐색
                curr = curr->right;
            }
        }
        
        // val을 추가하기 위해 탐색이 끝난 후 값을 추가한다.
        if (val < prev->val) {
            prev->left = new TreeNode;
            prev->left->val = val;
        }
        else {
            prev->right = new TreeNode;
            prev->right->val = val;
        }
        
        return root;
    }
};