class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> temp = nums;
        
        result.push_back(temp);
        next_permutation(temp.begin(), temp.end());
        
        while (temp != nums) {
            result.push_back(temp);
            next_permutation(temp.begin(), temp.end());
        }
        
        return result;
    }
};