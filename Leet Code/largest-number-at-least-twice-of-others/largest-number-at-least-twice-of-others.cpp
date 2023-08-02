class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        const size_t nums_length = nums.size();
        int max_val = 0;
        int max_index = 0;

        max_val = *max_element(nums.begin(), nums.end()); // 벡터 내부의 최대값
        max_index = max_element(nums.begin(), nums.end()) - nums.begin(); // 최대값의 인덱스
        
        for(size_t i = 0; i < nums_length; i++) {
            if (nums[i] != max_val && max_val < 2 * nums[i]) {
                return -1;
            }
        }
        
        return max_index;
    }
};