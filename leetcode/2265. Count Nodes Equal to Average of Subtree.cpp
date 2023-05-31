class Solution {
public:
    vector<int> dfs(TreeNode* root)
    {
        vector<int> result(2, 0); // 0 ==> sum 1 ==> count  총합과, 노드의 갯수 카운트 2개의 값을 리턴하기 위해 사용

        if  (root == nullptr) {
            return result;
        }
        
        vector<int> left_sum = dfs(root->left);
        vector<int> right_sum = dfs(root->right);

        result[0] = left_sum[SUM] + right_sum[SUM] + root->val; // 각 트리의 레벨별로 sum을 구함
        result[1] = left_sum[NODE_COUNT] + right_sum[NODE_COUNT] + 1; // 노드의 갯수를 카운드

        if (result[SUM] / result[NODE_COUNT] == root->val) {
            ++total_count; // 문제 조건에 일치하는 서브트리며 카운트
        }

        return result;
    }

    int averageOfSubtree(TreeNode* root) 
    {
        dfs(root);
        return total_count;
    }

private:
    int total_count = 0;
    
    enum { 
        SUM = 0, 
        NODE_COUNT = 1 
    };
};

// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/
