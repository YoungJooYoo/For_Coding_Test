class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        string result = "";
        
        for (const char& ch : s) {
            if (st.empty()) {
                st.push(ch);
            }
		    else if (st.top() == ch) {
                st.pop();
            }
		    else {
                st.push(ch);
            }
        }
        
        while (!st.empty()) {
            result += st.top(); // result = result + st.top() 하면 속도초과 발생
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};