class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
        if (root == NULL) { 
		     return 0;
        }
        
        int sum = 0;
        
		// 짝수인지 확인하고, 짝수라면 손자 노드 좌우 전부 탐색해서 sum에 누적한다.
        if (root->val % 2 == 0) {
            if (root->left != NULL && root->left->left != NULL) sum += root->left->left->val;
            if (root->left != NULL && root->left->right != NULL) sum += root->left->right->val;
            if (root->right != NULL && root->right->right != NULL)sum += root->right->right->val;
            if (root->right != NULL && root->right->left != NULL) sum += root->right->left->val;
        }
		
		//dfs
        sum += sumEvenGrandparent(root->left); // root의 자식들의 node를 탐색해서 다시 손자 노드를 더한 값을 누적한다.
        sum += sumEvenGrandparent(root->right);
		
        return sum;
    }
};