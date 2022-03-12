class Solution {
public:
    string helper(TreeNode* root)
    {
        if (root == nullptr) {
            return "";
        }
        
        /* 오른쪽 왼쪽 dfs로 탐색하면서 서브 트리를 만들어간다. */
        string l = helper(root->left);
        string r = helper(root->right);
        string s = "(" + l + to_string(root->val) + r + ")"; //make unique string of each subtree 
        
        if (mp[s] != -1) { // if string is not present insert and increase count
            mp[s]++;
        }
        if (mp[s] > 1) { // if same string found more than one time we got same subtrees
            ans.push_back(root);
            mp[s] = -1; // no need to insert again
        }
        
        return s; 
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        helper(root);
        return ans;
    }
    
private:
    vector<TreeNode*> ans; 
    unordered_map<string, int> mp; // 문자열-빈도수 해시맵으로, 서브트리 확인, 여기에는 모든 서브트리가 들어간다.
};