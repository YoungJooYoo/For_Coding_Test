class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res = {{}};
        vector<int> curr;
        
        for (const int& num : nums) {
            size_t array_size = res.size();
            
            for (size_t i = 0; i < array_size; i++) {
                curr = res[i];
                curr.push_back(num);
                res.push_back(curr);
            }
        }
        
        return res;
    }
};