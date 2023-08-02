class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        const int ARR_SIZE = nums.size();
        int total = 0;
        int max_len = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
       
        for (int num : nums) total += num;
        if (total == x) return ARR_SIZE;
        
        int sub_sum = total - x;
        
        while (right < ARR_SIZE) {
            sum += nums[right];  
            while(left < right && sum > sub_sum) {
                sum -= nums[left++];
            }
            if (sum == sub_sum) {
                max_len = max(len, right - left + 1);
            }
            right++;
        } 
        
        if (len == 0) {
            return -1;
        }  
        
        return ARR_SIZE-  max_len;
    }
};
