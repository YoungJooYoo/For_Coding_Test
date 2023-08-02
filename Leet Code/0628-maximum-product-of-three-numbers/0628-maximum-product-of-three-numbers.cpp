class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        int begin_max = nums[0] * nums[1] * nums[size - 1]; // 음수 2개와 양수중 가장 큰 수 곱한 값
        int end_max = nums[size - 1] * nums[size - 2] * nums[size - 3]; // 양수 3개를 곱한 값
        
        return max(begin_max, end_max);
    }
};