class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        const int ARR_SIZE = nums.size();
        int total = 0;
        int current = 0;
        int ans = -1;
        int left = 0;
        
        // 전체 합 구하기
        for (const int& num : nums) {
            total += num;
        }

        for (int right = 0; right < ARR_SIZE; right++) {
            current += nums[right];
            while (current > total - x && left <= right) {
                current -= nums[left];
                left += 1;
            }
            if (current == total - x) {
                int length = right - left + 1;
                ans = max(ans, length);
            }
        }
        
        if (ans != -1) {
            return ARR_SIZE - ans;
        }
        
        return -1;
    }
};