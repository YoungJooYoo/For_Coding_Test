class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int min_val = 100000, int max_val = 0) 
    {
        if (root == nullptr) {
            return max_val - min_val;
        }
        
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        
        return max(maxAncestorDiff(root->left, min_val, max_val), maxAncestorDiff(root->right, min_val, max_val));
    }
};

/*
풀이법 :
재귀로 탐색하면서, 좌우로 노드가 갈라지며 탐색할때마다
노드의 값을 체크해 최대값 최소값을 업데이트 한다.
트리의 마지막 끝 부분에 도달하면 최종적으로 max_val - min_val을 반환하고, 이 반환된 값에서 다시 max값을 뽑으면서
재귀를 반복한다.
*/