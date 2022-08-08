class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, ans, curr, 0);
        return ans;
    }
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curr, int index) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(index >= candidates.size()) return;
        if(target >= candidates[index]) {
            curr.push_back(candidates[index]);
            backtrack(candidates, target - candidates[index], ans, curr, index + 1);
            curr.pop_back();
            while(index + 1 < candidates.size() && candidates[index + 1] == candidates[index]) ++index;
            backtrack(candidates, target, ans, curr, index + 1);
        }
    }
};