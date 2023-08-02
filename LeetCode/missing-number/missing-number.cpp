class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t numbers[10000 + 1] = {0, };
        const size_t nums_length = nums.size();// nums의 길이 값이 숫자의 범위
        size_t result;
        
        for (size_t i = 0; i < nums_length; i++) {
            numbers[nums[i]] = 1; // flag on, checked, visited
        }
        
        for (size_t i = 0; i < nums_length; i++) {
            if (numbers[i] == 0) {
                return i;
            }
        }
        
        return result;
    }
};