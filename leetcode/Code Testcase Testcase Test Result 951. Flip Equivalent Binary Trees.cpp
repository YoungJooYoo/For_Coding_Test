class Solution 
{
public:
    bool flipEquiv(const TreeNode* const root1, const TreeNode* const root2) 
    {
        if (root1 == nullptr && root2 == nullptr) 
        {
            return true;
        }
        else if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) 
        {
            return false;
        }
        
        const bool case1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right); // 트리가 서로 모양이 같은 경우
        const bool case2 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left); // 트리 모양잉 서로 다르 뒤집힌 경우
        
        return case1 || case2;
    }
};

// https://leetcode.com/problems/flip-equivalent-binary-trees/description/
