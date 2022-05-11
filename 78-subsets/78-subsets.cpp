class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        vector<int> curr;
        int size;
        
        for (auto num : nums) {
            size = res.size();
            
            for (int i = 0; i < size; i++) {
                curr = res[i];
                curr.push_back(num);
                res.push_back(curr);
            }
        }
        
        return res;
    }
};