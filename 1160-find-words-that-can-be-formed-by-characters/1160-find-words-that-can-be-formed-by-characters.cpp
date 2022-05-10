class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int cnt[26] = {0, }; 
        int res = 0;
        
        // 알파벳의 빈도수 체크
        for (const char& ch : chars) {
            ++cnt[ch - 'a'];
        }
        
        for (const string& w : words) {
            int cnt1[26] = {};
            bool match = true;
            for (auto ch : w) {
                if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
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