class Solution {
 public:
    string reverseWords(string s) 
    {
        const size_t str_length = s.size();
        int idx = 0;
        
        reverse(s.begin(), s.end());
        
        for (size_t start = 0; start < str_length; ++start) {
            if (s[start] != ' ') {
                // go to the beginning of the word
                if (idx != 0) {
                    s[idx++] = ' ';
                }

                // go to the end of the word
                int end = start;
                while (end < str_length && s[end] != ' ') s[idx++] = s[end++];

                // reverse the word
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // move to the next word
                start = end;
            }
        }
        
        s.erase(s.begin() + idx, s.end());
        
        return s;
    }
};