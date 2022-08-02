class Solution {
public:
    void reverseWords(vector<char>& s) 
    {
        const size_t SIZE = s.size();
        stack<string> st;
        vector<char> result;
        string temp = "";
        size_t count = 0;
        
        // 단어별로 만들어서 넣기
        for (const auto& ch : s) {
            count++;
            if (ch != ' ') {
                temp += ch;
            }
            if (ch == ' ' || count == SIZE) {
                st.push(temp);
                temp = "";
            }
            
        }
        
        while (!st.empty()) {
            size_t st_size = st.size();
            string str = st.top(); st.pop();
            for (const auto& ch : str) {
                result.push_back(ch);
            }
            if (st_size > 1) {
                result.push_back(' ');
            }
        }
        
        s = result;
    }
};