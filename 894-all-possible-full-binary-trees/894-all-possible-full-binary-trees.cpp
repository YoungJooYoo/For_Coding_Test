class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        vector<TreeNode*> ans;

        if (n < 1 || n % 2 == 0) { // n이 짝수라면 완전 이진트리로 만드는 것이 불가능하다.
            return ans;
        }
        
        for (int k = 2; k < n; k += 2) { // 이진 트리를 만들 좌우 노드 생성, 루트는 있다고 가정하면 k=2부터
            vector<TreeNode*> v1 = allPossibleFBT(k - 1); //
            vector<TreeNode*> v2 = allPossibleFBT(n - k);
            cout << "k - 1 : " << k - 1 << endl;
            cout << "n - k : " << n - k << "\n " << endl;
            const size_t n1 = v1.size();
            const size_t n2 = v2.size();
            
            for (size_t i = 0; i < n1; i++) {
                for (size_t j = 0; j < n2; j++) {
                    TreeNode* newRoot = new TreeNode(0);
                    newRoot->left = v1[i];
                    newRoot->right = v2[j];
                    ans.push_back(newRoot);
                }
            }
        }
        
        if (ans.empty()) { // if N == 1
            ans.push_back(new TreeNode(0));
        }
        
        return ans;
    }
};