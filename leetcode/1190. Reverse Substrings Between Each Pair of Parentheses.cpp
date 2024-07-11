class Solution {
public:
    string reverseParentheses(const string& s) 
    {
        stack<string> st;
        string current;

        for (const auto ch : s)
        {   
            if (ch == '(')
            {
                st.push(current);
                current.clear();
               
            }
            else if (ch == ')')
            {
                reverse(current.begin(), current.end());
                if (!st.empty()) 
                {
                    current = st.top() + current;
                    st.pop();
                }
            }
            else
            {
                current.push_back(ch);
            }
        }

        return current;
    }
};
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2024-07-11

/*
1190. 각 괄호 쌍 사이의 부분 문자열 뒤집기

난이도: 중간

문제 설명
소문자 영어 문자와 괄호로 구성된 문자열 s가 주어집니다.

가장 안쪽의 괄호 쌍부터 시작하여, 각 괄호 쌍 사이의 문자열을 뒤집으세요.

결과 문자열에는 괄호가 포함되지 않아야 합니다.

예제
예제 1:

입력: s = "(abcd)"
출력: dcba
예제 2:

입력: s = "(u(love)i)"
출력: iloveu
설명: 먼저 "love" 부분 문자열을 뒤집고, 그런 다음 전체 문자열을 뒤집습니다.
예제 3:

입력: s = "(ed(et(oc))el)"
출력: leetcode
설명: 먼저 "oc" 부분 문자열을 뒤집고, 그런 다음 "etco"를 뒤집고, 마지막으로 전체 문자열을 뒤집습니다.
제약 조건
1 <= s.length <= 2000
s는 소문자 영어 문자와 괄호만 포함합니다.
모든 괄호는 균형이 잡혀 있음이 보장됩니다.
문제 풀이 힌트
이 문제를 해결하기 위한 접근 방법 중 하나는 스택을 사용하는 것입니다. 괄호의 쌍을 처리하기 위해 스택 자료구조를 사용할 수 있습니다. 다음은 문제를 해결하기 위한 단계별 접근 방법입니다:

스택 사용:

여는 괄호 '('를 만나면 현재 문자열을 스택에 저장하고 빈 문자열로 초기화합니다.
닫는 괄호 ')'를 만나면 스택에서 문자열을 꺼내어 현재 문자열을 뒤집은 후 꺼낸 문자열에 이어붙입니다.
문자 순회:

문자열 s를 순회하면서 각 문자를 처리합니다.
여는 괄호를 만나면 현재까지의 문자열을 스택에 저장하고 초기화합니다.
닫는 괄호를 만나면 현재 문자열을 뒤집고, 스택에서 이전 문자열을 꺼내어 이어붙입니다.
일반 문자는 현재 문자열에 계속 추가합니다.

*/
