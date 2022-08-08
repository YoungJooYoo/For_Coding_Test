class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        recursive(candidates, target, 0);
        
        return result;
    }
    
    void recursive(vector<int>& candidates, int target, int index) 
    {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i - 1] == candidates[i]) {
                continue;
            }
            if (target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                recursive(candidates, target - candidates[i], i + 1);
                temp.pop_back();
            }
            else {
                return;
            }
        }
    }
    
private:
    vector<vector<int>> result;
    vector<int> temp;
};