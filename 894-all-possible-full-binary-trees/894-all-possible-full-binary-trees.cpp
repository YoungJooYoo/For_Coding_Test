class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        vector<TreeNode*> ans;

        
        if (n < 1 || n % 2 == 0) {
//          it is impossible to have a full binary
//          tree on an even number of nodes
//          (both left and right subtrees must be full, 
//          + 1 for the root makes it an odd number of nodes)
            return ans;
        }
        
        for (int k = 2; k < n; k += 2) {
//          get all possible left and right subtree roots
            vector<TreeNode*> v1 = allPossibleFBT(k - 1);
            vector<TreeNode*> v2 = allPossibleFBT(n - k);
            const size_t n1 = v1.size();
            const size_t n2 = v2.size();
            
            for (size_t i = 0; i < n1; i++) {
                for(size_t j = 0; j < n2; j++) {
                    TreeNode* newRoot = new TreeNode(0);
                    newRoot->left = v1[i];
                    newRoot->right = v2[j];
                    ans.push_back(newRoot);
                }
            }
        }
        
        if (ans.empty()) {
//          if N == 1
            ans.push_back(new TreeNode(0));
        }
        
        return ans;
    }
};