class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int count = 0;
        
        for (size_t i = 0; i < nums.size() - 1; i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};