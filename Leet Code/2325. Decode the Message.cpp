class Solution {
public:
    string decodeMessage(string key, string message) 
    {
        unordered_map<char, char> dic;
        char value = 'a';
        dic[' '] = ' ';

        for (const auto& ch : key) {
            if (dic.find(ch) == dic.end() && ch != ' ') {
                dic[ch] = value++;
            }
        }

        for (auto& ch : message) {
            ch = dic[ch];
        }

        return message;
    }
};

// https://leetcode.com/problems/decode-the-message/description/
