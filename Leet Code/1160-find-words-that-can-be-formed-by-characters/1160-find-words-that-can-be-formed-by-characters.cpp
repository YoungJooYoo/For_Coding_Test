class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int count_chars[26] = {0, }; 
        int res = 0;
        
        // 알파벳의 빈도수 체크
        for (const char& ch : chars) {
            count_chars[ch - 'a']++;
        }
        
        for (const string& word : words) {
            int word_count[26] = {0, };
            bool match = true;
            for (const char& ch : word) { // 배열에 있는 문자열의 빈도수를 체크한다.
                if (++word_count[ch - 'a'] > count_chars[ch - 'a']) { // 빈도수가 일치 하지 않으면 false처리,  chars가 words를 내포해야하는 조건식
                    match = false;
                    break;
                }
            }
            if (match == true) {
                res += word.size();
            }
        }
        
        return res;
    }
};