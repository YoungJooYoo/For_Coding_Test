class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        const size_t input_size = digits.size();
        int i;
        int num = 0;
        
        // 뒷자리부터 탐색 9가 아니면 +1 하고, 9라면 0으로 바꾸고 for문 돌면서
        // 9가 아닌 원소(다음을 계속 탐색) 찾으면 + 1하고 종료
         for (i = input_size - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }
 
        // 원소가 9 9 9 9 라면 원소 4개가 0으로 되므로 0 0 0 0이다.
        // 이런 경우 벡터 배열 맨 앞에 1을 더해주는 것이다.
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
};