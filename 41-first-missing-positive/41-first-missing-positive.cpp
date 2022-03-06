class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        const size_t n = nums.size();
        
        for (size_t i = 0 ; i < n; i++) {
            while (nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1]) { // 양수만 신경쓰기, 중복 제거하기
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (size_t i = 0 ; i < n ; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};