class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
	{
        if (root1 == nullptr) {
			return root2;
		}
        if (root2 == nullptr) { 
			return root1;
		}
            
        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

/*
풀이법 :
root1에 결과를 합산할 것이다.

root1에서 null이고, root2에서 null 아닌 leaf가 있다면
root1에 root2의 노드를 이어붙인다.
반대로,
root2가 존재하지 않고, root1만 존해마녀 root1 leaf만 사용

둘다 존재하면 두 노드의 val을 더해서 root1 노드에 저장한다.

*/