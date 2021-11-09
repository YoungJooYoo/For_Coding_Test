class Solution {
public:
    string reverseWords(string s) {
        const size_t str_length = s.size();
        int begin = 0;
        int end;
        
        for (size_t i = 0; i <= str_length; i++) { 
            if(s[i] == ' ' || i == str_length) {
                end = i - 1; // 공백이 나온 i 직전부터
                while(begin < end) {
                    swap(s[begin], s[end]);
                    begin++;
                    end--;
                } // end of while
                begin = i + 1; // 공백 다음부터 시작
            } // end of if
        } // end of for
        
        return s;
    }
};