class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        const size_t arr_length = nums.size();
        long long sum = 0;
        
        for (size_t i = 0; i < arr_length; i++) {
            int min = nums[i];
            int max = nums[i];
            for (size_t j = i; j < arr_length; j++) {
                if (nums[j] < min) {
                    min = nums[j];
                }
                if (nums[j] > max) {
                    max = nums[j];
                }
                sum += max - min;
            }
        }
        
        return sum;
    }
};