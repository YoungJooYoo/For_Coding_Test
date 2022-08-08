class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        
        return ans;
    }
    
    void backtrack(vector<int>& candidates, int target, int index) 
    {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        else if (index >= candidates.size()) {
            return;
        }
        else if (target >= candidates[index]) {
            curr.push_back(candidates[index]);
            backtrack(candidates, target - candidates[index], index + 1);
            curr.pop_back();
            while (index + 1 < candidates.size() && candidates[index + 1] == candidates[index]) { // 중복값이면 체크
                index++; // 중복이면 인덱스를 쭈욱 넘긴다
            }
            backtrack(candidates, target, index + 1);
        }
    }
    
private:
    vector<vector<int>> ans;
    vector<int> curr;
};