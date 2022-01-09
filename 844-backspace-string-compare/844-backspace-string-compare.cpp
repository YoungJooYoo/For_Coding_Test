class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        bool ans;
        stack<char> s1;
        stack<char> t1;
               
        for (size_t i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if (s1.empty() == true) {
                    continue;
                }
                s1.pop();
            }
            else {
                s1.push(s[i]);
            }
        }
        
        for (size_t i = 0; i < t.size(); i++) {
            if(t[i] == '#') {
                if (t1.empty() == true) {
                    continue;
                }
                t1.pop();
            }
            else {
                t1.push(t[i]);
            }
        }
        
        return s1 == t1 ? true : false;
    }
};