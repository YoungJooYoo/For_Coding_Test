class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        vector<TreeNode*> tree;
        
        if (memo.find(N) != memo.end()) {
            return memo[N];
        }
        if (N == 1) { // 루트 노드를 만들어서 반환
            return memo[N] = {new TreeNode(0)};
        }
        if (N % 2 == 0) { // 짝수면 빈 것을 반환, 짝수며 정확하게 완전 2진트리 만들기기 불가능하다
            return {};
        }
        
        for (int x = 0; x < N ; ++x) {
            int y = N - x - 1;
            for (const auto l: allPossibleFBT(x)) {
                for (const auto r: allPossibleFBT(y)) {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    tree.push_back(root);
                }
            }
        }
        
        return memo[N] = tree;
    }
private:
    unordered_map<int, vector<TreeNode*>> memo;
};

/* 
풀이법 :  
n = 5 개는 n = 3개일때 나오는 트리의 모습을 내포한다.
다시, n = 7은 n = 5일때 트리 모습을 가지고 있다. 즉 이전의 트리 노드의 모습을
재사용하면서 n이 커질때 마다 트리의 모습이 나오게 된다.

https://leetcode.com/problems/all-possible-full-binary-trees/discuss/944704/C%2B%2B-DP-with-simple-explanation
*/