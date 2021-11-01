class Solution {
public:
    int arraySign(vector<int>& nums) {
        const size_t nums_length = nums.size();
        size_t negative_count = 0;
        
        // 0을 찾았다면, 그 자리에서 0을 반환
        for (size_t i = 0; i < nums_length; i++) {
            if (nums.at(i) == 0) {
                return 0;
            } 
            else if (nums.at(i) < 0) { // 음수의 갯수를 카운팅
                negative_count++;
            }
        }
        
        if (negative_count % 2 == 0) { // 음수의 갯수가 짝수면 모든 원소 곱이 양수이므로
            return 1;
        }
        else { // 음수의 갯수가 홀수라면 모든 원소 곱셈값은 음수
            return -1;
        }
   
        return 0;
    }
};