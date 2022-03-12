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
        string s = "(" + l + to_string(root->val) + r + ")";
        
        if (mp[s] != -1) { // 이미 사용된 서브트리가 아니라면 빈도수체크
            mp[s]++;
        }
        if (mp[s] > 1) { // 빈도수가 1이상이면 중복이라 간주하고, 배열에 넣는다.
            ans.push_back(root);
            mp[s] = -1; // 서브트리 사용했다고 표시
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