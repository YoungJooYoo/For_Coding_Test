class Solution {
public:
    string reverseWords(string s) {
        string res; 
        string tmp;
        
        size_t i = 0; 
        size_t j;
        const size_t len = s.size();
        
        while (true) {
            while (i < len && s[i] == ' ') { // 공백이면 무시
                i++;
            }
            if (i >= len) {
                break; // 문자열 끝까지 갔다면 종료
            }
            j = i + 1;
            while (j < len && s[j] != ' ') j++; // 공백이 아니면 인덱스 전진
            tmp = s.substr(i, j - i); // 단어별로 서브스트링 생성
            res = tmp + (res.size() ? " " : "") + res;
            // moving to the next word
            i = j + 1;
        }
        
        return res;
    }
};