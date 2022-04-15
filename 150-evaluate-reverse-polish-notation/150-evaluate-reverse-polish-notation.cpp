class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1;
        int op2;
        
        for(string s: tokens) {
            if(s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            }
            else {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                
                if(s == "+") {
                    st.push(op1 + op2);
                }
                else if(s == "-") {
                    st.push(op1 - op2);
                }
                else if(s == "*") {
                    st.push(op1 * op2);
                }
                else if(s == "/") {
                    st.push(op1 / op2);
                }
            } 
        }
        
        return st.top();
    }
};

// 이 문제는 스택의 후위표기 연산을 구현하는 것
// 후위연산으로 답을 구해라
