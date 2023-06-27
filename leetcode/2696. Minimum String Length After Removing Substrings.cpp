class Solution {
public:
    int minLength(string s) 
    {
        stack<char> st;

        for (const auto& ch : s) {
            if (st.empty() == false && st.top() == 'A' && ch == 'B') st.pop();
            else if (st.empty() == false && st.top() == 'C' && ch == 'D') st.pop();
            else st.push(ch);
        }

        return st.size();
    }
};

// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/
