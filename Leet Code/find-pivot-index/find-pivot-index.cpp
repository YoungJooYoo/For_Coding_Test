class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const size_t nums_length = nums.size();
        size_t left_sum = 0; // 문제조건 좌측합은 시작 0
        size_t sum = 0;
        
        // 배열의 합 구하기
        for (size_t i = 0; i < nums_length; i++) {
            sum = sum + nums[i];
        }
        
        // 구한 배열의 함을 이용해, 원소를 하나씩 빼면서 비교
        // 좌측합은 원소를 하나씩 더하면서 sum과 left_sum 비교
        for (size_t i = 0; i < nums_length; i++) {
            sum = sum - nums[i];
            if (sum == left_sum) {
                return i;
            }  
            else {
                left_sum = left_sum + nums[i];
            }
        }
    
        return -1; // 답이 없으면 return -1
    }
};