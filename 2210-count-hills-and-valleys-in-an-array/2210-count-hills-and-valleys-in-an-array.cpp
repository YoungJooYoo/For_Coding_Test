class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // 중복값 제거
        int result = 0;
        
        for(size_t i = 1; i < nums.size() -1; ++i) {
            result += (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])  || (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]); // hill and valley
        }
        
        return result;
    }
};