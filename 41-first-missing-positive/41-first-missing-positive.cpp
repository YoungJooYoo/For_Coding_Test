class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        const size_t n = nums.size();
        
        // 배열을 배열 인덱스에 맞게 숫자를 정렬한다.
        for (size_t i = 0 ; i < n; i++) {
            while (nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1]) { // 양수만 신경쓰기
                swap(nums[i], nums[nums[i] - 1]); // 인덱스에 맞게 숫제 정렬하기
            }
        }
        
        // 정렬된 배열을 탐색하면서, 배열의 값과 인덱스를 매칭 시켜두었는데 그 값이 일치 하지 않으면,
        // 그 값이 비는 것으로 간주하고 모자른 값인 i + 1을 반환한다.
        for (size_t i = 0 ; i < n ; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};