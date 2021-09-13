class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // ( { [ 3가지 문자를 스택에 저장
        for (size_t i = 0; i < s.size(); i++) {
            if (s.at(i) == '{' || s.at(i) == '(' || s.at(i) == '[') {
                st.push(s.at(i));
            }
            else { // 저장하는 중에 첫원소 지나고 empty면 전부 false이므로 false 반환
                if (st.empty()) {
                    return false;
                } // 서로 짝이 맞는 문자{} () [] 서로 만나면 push한다
                else {
                    if ((s.at(i) == '}' && st.top() != '{') || (s.at(i) == ')' && st.top() != '(') || (s.at(i) == ']' && st.top() != '[')) {
                        st.push(s.at(i));
                    }
                    else {
                        st.pop();
                    }
                }
            }
        }

        return st.empty();
    }
};
