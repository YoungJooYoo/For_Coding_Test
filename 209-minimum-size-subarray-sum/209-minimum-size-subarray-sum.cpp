class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left = 0;
        int right = 0; 
        int n = nums.size();
        int sum = 0;
        int length = INT_MAX;
        
        while (right < n) {
            sum += nums[right++];
            while (sum >= target) {
                length = min(length, right - left);
                sum -= nums[left++];
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};