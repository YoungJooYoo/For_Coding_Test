class Solution {
 public:
    string reverseWords(string s) 
    {
        const size_t str_length = s.size();
        int idx = 0;
        
        reverse(s.begin(), s.end());
        
        for (size_t start = 0; start < str_length; ++start) {
            if (s[start] != ' ') {
                if (idx != 0) { // go to the beginning of the word
                    s[idx++] = ' ';
                }
                size_t end = start; // go to the end of the word
                while (end < str_length && s[end] != ' ') {
                    s[idx++] = s[end++];
                }
                reverse(s.begin() + idx - (end - start), s.begin() + idx); // reverse the word
                start = end; // move to the next word
            }
        }
        
        s.erase(s.begin() + idx, s.end());
        
        return s;
    }
};