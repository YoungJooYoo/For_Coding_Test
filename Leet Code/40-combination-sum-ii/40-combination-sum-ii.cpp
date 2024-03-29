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
            if (i != index && candidates[i - 1] == candidates[i]) { // 시작인덱스와 같지 않으면서, 이전 값과 현재 인덱스 값이 같은 경우 pass
                continue; // 중복 제거를 위한 부분
                // 동일한 원소가 들어가지 않아야, 중복된 답을 넣지 않는다. (처음 사용되는 숫자를 제외하며, 동일하면 건너뛴다)
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