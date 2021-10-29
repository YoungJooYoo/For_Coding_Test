class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const size_t nums_size = nums.size();
        size_t count = 1; // 카운트가 3이되면, 그 숫자가 3번쨰로 큰수
        int result;
        
        sort(nums.begin(), nums.end());
        
        // 3보다 작은경우 정렬된 값의 최대값(맨뒤의값) 출력
        if (nums_size < 3) {
            return nums[nums_size - 1];
        }
        
        // 정렬된 배열에서 가장 큰 수다음부터 비교 뒤에서 두번째 원소부터 쭈욱 비교
        for(int i = nums_size -2; i >= 0; i--) {
            if(count < 3 && nums[i + 1] != nums[i]){ // 3번째 큰수 탐색
                count++;
                result = nums[i];
            }
        }
        if(count < 3){ // 3번째 큰수가 없다면, 2번쨰로 혹은 첫번째로 큰수 반환
            result = nums[nums_size - 1];
        }
        
        return result;
    }
};