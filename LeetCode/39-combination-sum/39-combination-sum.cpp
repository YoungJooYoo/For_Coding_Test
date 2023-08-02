class Solution 
{
public:
    void recursive(vector<int>& candidates, int target, int index)
    {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(temp);
        }
        
        for (int i = index; i < candidates.size(); i++) {
            sum += candidates[i]; // 합산 누적
            temp.push_back(candidates[i]);  // 임시 배열 추가
            recursive(candidates, target, i);
            sum -= candidates[i]; // 백트랙킹 더 한 것 빼고
            temp.pop_back(); // 추가한 원소 삭제
        }      
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        recursive(candidates, target, 0);
        return result;
    }
    
private:
    vector<vector<int>> result;
    vector<int> temp;
    int sum = 0; 
};