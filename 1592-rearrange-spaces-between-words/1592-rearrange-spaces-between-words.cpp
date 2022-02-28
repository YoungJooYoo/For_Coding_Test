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
                spaces++;
                if (!word.empty()) {
                    words.push_back(word);
                }
                word = "";
            }
            else {
                word += ch;
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