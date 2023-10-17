class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string result;

        while (columnNumber != 0) {
            int temp = columnNumber - 1; // index for char
            result.push_back('A' + temp % ALPHABET_LENGTH);
            columnNumber = temp / ALPHABET_LENGTH;    
        }
        reverse(result.begin(), result.end());

        return result;
    }

private:
    enum { ALPHABET_LENGTH = 26 };
};

// https://leetcode.com/problems/excel-sheet-column-title/description/
