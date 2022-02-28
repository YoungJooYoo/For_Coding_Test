class Solution {
public:
    string reorderSpaces(string text) 
    {
        int spaces = 0;
        string word;
        string s;
        vector<string> words;
        
        
        for (const auto& ch : text) {
            if (ch == ' ') {
                spaces++; /* 문자열 text에서 공백의 갯수를 카운트한다. */
                if (!word.empty()) { /*공백을 재거한 단어들을 words 배열에 넣는다. */
                    words.push_back(word);
                }
                word = ""; // 문자열 word 초기화
            }
            else {
                word += ch; // 단어를 누적한다.
            }
        }
        
        if (!word.empty()) {
            words.push_back(word);
        }
        if (words.size() == 1) {
            return words.back() + string(spaces, ' ');
        }
        
        int gap = spaces / (words.size() - 1);
        int suff = spaces % (words.size() - 1);
        
        for (const auto& w : words) {
            s += w + string(gap, ' ');
        }
        
        return s.substr(0, s.size() - gap) + string(suff, ' ');
    }
};