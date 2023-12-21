class Solution {
public:
    int minimumMoves(const string& s) 
    {
        const size_t LEN = s.size();
        size_t i = 0;
        int count = 0;

        while (i < LEN) {
            if (s[i] == 'X') {
                i += 3;
                ++count;
            }
            else {
                ++i;
            }
        }

        return count;
    }
};


// https://leetcode.com/problems/minimum-moves-to-convert-string/description/
