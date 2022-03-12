class Solution {
 public:
    string reverseWords(string s) 
    {
        const size_t str_length = s.size();
        int idx = 0;
        
        reverse(s.begin(), s.end()); // 문자열을 뒤집고 시작한다.
        
        for (size_t start = 0; start < str_length; ++start) {
            if (s[start] != ' ') { // 시작점이 공백이면
                if (idx != 0) { // go to the beginning of the word // 시작점이 공백이면
                    s[idx++] = ' ';
                }
                
                size_t end = start; // 단어의 끝으로 이동
                
                while (end < str_length && s[end] != ' ') {
                    s[idx++] = s[end++];
                }
                reverse(s.begin() + idx - (end - start), s.begin() + idx); // 단어별로 다시 reverse
                start = end; // 다음단어로 이동
            }
        }
        
        s.erase(s.begin() + idx, s.end());
        
        return s;
    }
};