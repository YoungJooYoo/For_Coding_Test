class Solution {
public:
    string finalString(string& s) 
    {
        string result;

        for (const auto& ch : s) {
            if (ch == 'i') {
                reverse(result.begin(), result.end());
            }
            else {
                result.push_back(ch);
            }
        }

        return result;
    }
};

// s.erase(remove(s.begin(), s.end(),'i'), s.end());

// https://leetcode.com/problems/faulty-keyboard/description/
