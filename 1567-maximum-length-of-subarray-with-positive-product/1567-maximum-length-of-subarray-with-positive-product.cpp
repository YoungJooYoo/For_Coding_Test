class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int max_length = 0;
        int positive_count = 0;
        int negative_count = 0;
        
        for (const auto& num : nums) {
            if (num == 0) { // 원소가 0 이라면, 패스 카운트 전부 초기화
                positive_count = 0;
                negative_count = 0;
            }
            if (num < 0) { // 음수인 경우 체크, 음수가 짝수가 되어야 유효한 길이가 된다
                int temp_pos = positive_count; // 양수의 갯수 임시 저장
                if (negative_count != 0) { // true 라면
                    negative_count++;
                }
                else { // netative가 0보다 크다면
                    negative_count = 0;
                }
                positive_count = negative_count;
                negative_count = temp_pos + 1; // 양수 갯수 + 1
            }
            if (num > 0) { // 양수인 경우
                if (negative_count != 0) {
                    negative_count++;  // 왜왜왜????
                }
                positive_count++; // 양수 갯수 카운트 
            }
            max_length = max(max_length, positive_count);
        }
        
        return max_length;
    }
};