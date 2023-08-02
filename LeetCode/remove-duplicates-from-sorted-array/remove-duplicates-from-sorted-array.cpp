class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
        int index = 1; // 원소 0번쨰는 항상 고정이므로 1번부터 시작
        
        // 입력부 예외처리
        if (nums.size() < 1) {
            return nums.size();
        }
        
        // nums 0은 고정 1번부터 값이 수정된다.
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if(nums[i] != nums[i + 1]) {
                nums[index] = nums[i + 1];
                index++;
            }
        }
        return index;
    } 
};