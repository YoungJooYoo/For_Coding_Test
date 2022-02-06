class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> temp = nums;
        
        result.push_back(temp);
        next_permutation(temp.begin(), temp.end()); // 다음순열 계산
        
        while (temp != nums) { // input 값과 같을때까지, 계속 순열의 원소를 계산한다.
            result.push_back(temp);
            next_permutation(temp.begin(), temp.end());
        }
        
        return result;
    }
};