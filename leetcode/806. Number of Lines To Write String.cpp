class Solution {
public:
    vector<int> numberOfLines(const vector<int>& widths, const string& s) 
    {
        int lines = 1; // 총 줄 수
        int lastLineWidth = 0; // 마지막 줄의 너비

        for (const char ch : s) {
            const int width = widths[ch - 'a']; // 해당 문자의 너비
            if (lastLineWidth + width > 100) { // 총 너비가 100을 넘으면 다음 줄로 넘어감
                ++lines;
                lastLineWidth = width;
            } 
            else {
                lastLineWidth += width;
            }
        }

        return {lines, lastLineWidth};
    }
};

// https://leetcode.com/problems/number-of-lines-to-write-string/
