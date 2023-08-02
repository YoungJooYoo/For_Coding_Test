class Solution {
private:
    bool ans;
    
public:
    int check_balance(TreeNode* root)
    {
        if(root == NULL) {
            return 0;
        }
        if(ans == false) {
            return 0;
        }
        
        int left_subtree = check_balance(root->left);
        int right_subtree = check_balance(root->right);
        
        // 최종적으로 루트 노드로 돌아오는 반환값 왼쪽과 오른쪽의 깊이를 비교
        // 그 크기가 1이 넘어가면 false가 된다.
        if(abs(left_subtree - right_subtree) > 1) {
            ans = false;
        }
        
        // 트리의 맨 아래부터 카운트하며 올라간다.
        return 1 + max(left_subtree, right_subtree);
    }
    
    bool isBalanced(TreeNode* root)
    {
        ans = true;
        int temp = check_balance(root);
        
        return ans;
    }
};