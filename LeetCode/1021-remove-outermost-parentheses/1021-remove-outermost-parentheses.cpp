class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string ans = "";
        stack<char> st;
        
        for (const auto& ch : s) {
            if (ch == '(') {
                if (st.empty() == true) {
                    st.push(ch);    
                }
                else {
                    st.push(ch);
                    ans += ch;
                }
                
            }
            else { // ch == ')'
                st.pop();
                if (st.empty() == false) {
                    ans += ch;
                }
            }
        }        
        
        return ans;
    }
};