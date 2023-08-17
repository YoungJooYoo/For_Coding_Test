class Solution {
public:
    int minimizedStringLength(string s) 
    {
        unordered_set<char> st(s.begin(), s.end());
        return st.size();
    }
};

// https://leetcode.com/problems/minimize-string-length/description/
