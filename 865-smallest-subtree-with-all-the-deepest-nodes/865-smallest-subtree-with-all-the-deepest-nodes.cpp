class Solution {
public:
    int getDepth(TreeNode* root) // 현재 노드의 깊이를 구함 아래부터 0, 1, 2, 3 오름차순
    {
        if (root == nullptr) {
            return 0;
        }
        return max(getDepth(root->right), getDepth(root->left)) + 1;
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        if (root == nullptr) {
            return NULL;
        }
        
        int right_depth = getDepth(root->right);
        int left_depth = getDepth(root->left);
        
        if (right_depth == left_depth) { // 가장 갚은 노드를 찾는다.
            return root; // 가장 깊은 노드에서만 성립하는 조건문이다.
        }
        else if (right_depth > left_depth) {
            return subtreeWithAllDeepest(root->right);
        }
        else { // right_depth < left_depth
            return subtreeWithAllDeepest(root->left);
        }
    }
};