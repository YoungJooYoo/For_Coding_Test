class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int count = 0;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] <= 0) {
                if (count >= 1) {
                    return false;
                }
                if (i >= 2 && nums[i] - nums[i - 2] <= 0) { // 인덱스 2보다 큰 상황에서 다음다음 원소랑도 비교해서 진행
                    nums[i] = nums[i - 1]; // 더 큰 값 발견하면 덮어 씌운다 그 값을 끌고 와서 다음 원소랑 비교할 수 있게
                }
                ++ count;
            }
            
        }

        return true;
    }
};

// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/
