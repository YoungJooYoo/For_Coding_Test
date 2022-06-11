class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        const int ARR_SIZE = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        
        while (left <= right) {
            if (sum >= x) {
                if (sum == x) {
                    res = min(res, left + ARR_SIZE - right);
                }
                if (right < ARR_SIZE) {
                    sum -= nums[right++];
                }
                else {
                    break;
                }
            }
            else { // sum < x
                sum += nums[left];
                left++;
            }
        }
        
        if (res == INT_MAX) {
            return -1;
        }
        
        return res;
    }
};