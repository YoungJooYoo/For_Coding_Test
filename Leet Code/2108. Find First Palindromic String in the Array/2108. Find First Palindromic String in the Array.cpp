class Solution {
public:
    bool is_palindromic(string word)
    {
        int i = 0;
        int j = word.size() - 1;

        while (i < j) {
            if (word[i] != word[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) 
    {
        for (const auto& word : words) {
            if (is_palindromic(word) == true) {
                return word;
            }
        }

        return "";
    }
};

// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
