class Solution {
public:
    bool is_vowel(const char ch) 
    {
        if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') {
                return true;
        }

        return false;
    }

    string sortVowels(string& s) 
    {
        string temp;
        
        for (const auto& ch : s) {
            if (is_vowel(ch) == true) {
                temp.push_back(ch);
            }
        }

        sort(begin(temp), end(temp));
        size_t j = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (is_vowel(s[i]) == true) {
                s[i] = temp[j++];
            }
        }

        return s;
    }
};

// https://leetcode.com/problems/sort-vowels-in-a-string/description/
