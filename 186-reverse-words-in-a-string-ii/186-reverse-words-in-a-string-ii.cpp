class Solution {
public:
    void reverseWords(vector<char>& s) 
    {
        const size_t SIZE = s.size();
        stack<string> st;
        //vector<char> result;
        string temp = "";
        size_t count = 0;
        
        // 단어별로 만들어서 넣기, 스택에 넣기
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
        
        s.clear();
        // 스택에서 뽑아서, 다시 만들기
        while (!st.empty()) {
            size_t st_size = st.size();
            string str = st.top(); st.pop();
            for (const auto& ch : str) {
                s.push_back(ch);
            }
            if (st_size > 1) {
                s.push_back(' ');
            }
        }
        
        //s = result;
    }
};