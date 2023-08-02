
class Solution {
public:
    string decodeString(string s) 
    {
        stack<char> stack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') { // 스택에 문자를 적재하다 괄호가 끝나는 ]가 나오면 작업을 시작한다.
                string decodedString = "";
                
                // 괄호속 알파벳을 추출한다.
                while (stack.top() != '[') { // get the encoded string
                    decodedString += stack.top();
                    stack.pop();
                }
                stack.pop(); // pop [ from stack
                
                int base = 1;
                int k = 0; 
                // 괄호 앞의 숫자를 정수화한다. 즉 숫자를 구한다.
                while (!stack.empty() && isdigit(stack.top())) { // get the number k, 정수화작업
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }
                
                // 구한 숫자 K만큼 아까 구한 문자를 스택에 집어 넣는다.
                while (k != 0) { // decode k[decodedString], by pushing decodedString k times into stack
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString[j]);
                    }
                    k--;
                }
            }
            else { // push the current character to stack, 일반 문자를 스택에 계속 적재한다.
                stack.push(s[i]);
            }
        }
        
        // get the result from stack
        string result;
        for (int i = stack.size() - 1; i >= 0; i--) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};

