class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int count_chars[26] = {0, }; 
        int res = 0;
        
        // 알파벳의 빈도수 체크
        for (const char& ch : chars) {
            ++count_chars[ch - 'a'];
        }
        
        for (const string& w : words) {
            int cnt1[26] = {};
            bool match = true;
            for (auto ch : w) {
                if (++cnt1[ch - 'a'] > count_chars[ch - 'a']) {
                    match = false;
                    break;
                }
            }
            if (match) {
                res += w.size();
            }
        }
        
        return res;
    }
};