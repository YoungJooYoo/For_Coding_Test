class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int j = 0;

        for (const auto& elem : word) {
            if (elem == ch) {
                int i = 0;
                while (i < j) {
                    char temp = word[i];
                    word[i] = word[j];
                    word[j] = temp;
                    ++i;
                    --j;
                }
                return word;
            }
            ++j;
        }   

        return word; 
    }
};

// https://leetcode.com/problems/reverse-prefix-of-word/description/
