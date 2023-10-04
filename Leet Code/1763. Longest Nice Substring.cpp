class Solution {
public:
    bool check(const string const temp) const
    {
        for (size_t i = 0; i< temp.size(); ++i) {
            char ch = temp[i];
            if  (ch <= 'Z') ch += 32; // 대문사는 -> 소문자로, 소문자는 -> 대문자로 변경
            else ch -= 32;
            if (temp.find(ch) == string::npos) { // 변경된 문자 즉, 각 문자의 대소문자가 존재하는지 체크, 없다면 넘김
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstring(const string const s) const
    {
        const size_t LEN = s.size();
        string result;

        for (size_t i = 0; i < LEN; ++i) {
            string temp;
            temp += s[i];
            for(size_t j = i + 1; j < LEN; ++j) {
                temp += s[j];
                if (check(temp) == true && temp.size() > result.size()) {
                    result = temp;
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/longest-nice-substring/description/
