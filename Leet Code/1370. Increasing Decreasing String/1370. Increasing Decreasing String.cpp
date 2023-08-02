class Solution {
public:
    string sortString(string s) 
    {
        int alphbet[MAX] = {0, };
        string result;
        
        for (const char& ch: s) {
            alphbet[ch - 'a']++;
        }
            
        while (true) {
            for (int i = 0; i < MAX; ++i) {
                if (alphbet[i]-- > 0) {
                    result += 'a' + i;
                }
            }
            for (int i = MAX - 1; i >= 0; --i) {
                if (alphbet[i]-- > 0) {
                    result += 'a' + i;
                }
            }
            if (s.length() == result.length()) {
                break;
            }
        }

        return result;
    }

private:
    enum { MAX = 26 };
};

// https://leetcode.com/problems/increasing-decreasing-string/description/
