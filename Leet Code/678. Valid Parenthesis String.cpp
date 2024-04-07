class Solution {
public:
    bool checkValidString(const string& s) 
    {
        int min_open = 0; // 최소 열린 괄호의 개수
        int max_open = 0; // 최대 열린 괄호의 개수

        for (const char& c : s) {
            min_open += (c == '(') ? 1 : -1;
            max_open += (c != ')') ? 1 : -1;

            if (max_open < 0) break;// 닫힌 괄호 ')'의 개수가 열린 괄호 '('의 개수보다 많은 경우
                
            min_open = max(min_open, 0); // 음수 개수의 열린 괄호는 유효하지 않음
        }

        return min_open == 0 ? true : false; // 정확히 0개의 열린 괄호를 가질 수 있다면 유효한 문자열
    }
};


/*

주어진 문자열 `s`는 오직 세 종류의 문자만 포함합니다: '(', ')' 및 '*'. 문자열 `s`가 유효하다면 true를 반환하세요.

다음 규칙에 따라 유효한 문자열이 정의됩니다:

1. 모든 왼쪽 괄호 '('는 해당하는 오른쪽 괄호 ')'를 가져야 합니다.
2. 모든 오른쪽 괄호 ')'는 해당하는 왼쪽 괄호 '('를 가져야 합니다.
3. 왼쪽 괄호 '('는 해당하는 오른쪽 괄호 ')' 앞에 와야 합니다.
4. '*'는 단일 오른쪽 괄호 ')' 또는 단일 왼쪽 괄호 '(' 또는 빈 문자열 ""로 처리될 수 있습니다.

**예시:**

입력: s = "()"  
출력: true  
설명: 문자열이 "()"이므로 유효합니다.

입력: s = "(*)"  
출력: true  
설명: 문자열이 "(*)"이므로 유효합니다.

입력: s = "(*))"  
출력: true  
설명: 문자열이 "(*))"이므로 유효합니다. '*'는 단일 오른쪽 괄호 ')'로 처리될 수 있습니다.
*/

// https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2024-04-07
