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

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

	    reverse(result.begin(), result.end());

	    return result;
    }
};