class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        string ans = "";
        
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
            ans += st.top();
            st.pop();
        }

	    reverse(ans.begin(), ans.end());

	    return ans;
    }
};