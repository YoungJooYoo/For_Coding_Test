class Solution {
public:
    void solve(TreeNode* root) {
        //base case
        if(!root) return;
        
        //recursive case
        map[root->val]++;
        fre = max(fre, map[root->val]);
        solve(root->left);
        solve(root->right);
        
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
        fre = 0;
        solve(root);
        vector<int> res;
        
        for(auto &x: map){
            if(x.second == fre) res.push_back(x.first);
        }
        
        return res;
    }
    
private:
    unordered_map<int, int> map;
    int fre;
};