class Solution {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        int total_sum = accumulate(begin(nums), end(nums), 0); // 초기값을 0으로 두고 nums 배열 전부 더한다.
        int left_sum  = 0; // 배열의 첫인덱스부터 누적하면서 더하는 sum
        
        for (size_t i = 0; i < nums.size(); i++) {
            total_sum -= nums[i];
            if (left_sum == total_sum) {
                return i;
            }
            left_sum += nums[i];
        }
        
        return -1;
    }
};