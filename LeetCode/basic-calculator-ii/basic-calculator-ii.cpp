class Solution {
public:
    int calculate(string s) {
        const size_t s_length = s.size();
        vector<int> nums;
        int num = 0;
        int result = 0;
        char ops = '+';
        
        for (size_t i = 0; i <= s_length; i++) {
            if (s[i] >= '0' && s[i] <= '9') { // 문자열 숫자 -> 정수숫자 변환하기
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*' or i == s_length) { // 4칙 연산 중 하나라면 
                if (ops == '+' or ops == '-') { // +, - 경우 값을 저장해둔다. 추후 계산
                    ops == '+' ? num : (num = num * -1); // 덧셈인 경우, 뺄셈인 경우
                    nums.push_back(num);
                }
                else if (ops == '*' or ops == '/') { // 우선순위가 높은 곱셈 나눗셈부터 계산
                    ops == '*' ? (nums.back() = nums.back() * num) : (nums.back() = nums.back() / num); // 곱셉인 경우, 나눗셈인 경우
                    
                }
                num = 0; // num 초기화
                ops = s[i]; // 계산수식 업데이트
            }
        }
        
        for (size_t i = 0; i < nums.size(); i++) { // 최종값 결과 계산
            result = result + nums[i];
        }
        
        return result;
    }
};

// 왜 문자열 끝까지 // 왜 i == s_length 문자열끝에 오면 무엇을 하는가 == 마지막 문자가 들어가야 ops가 업데이트 된다. 그리고 계산 고고 하는 것 else if를 더 태우기 위해서!
// for문 문자열 끝에 가야지 덧셈이 계산된다.

