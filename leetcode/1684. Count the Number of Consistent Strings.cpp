class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int map[ALPHABET_SIZE] = { 0, };
        int count = 0;

        for (size_t i = 0; i < allowed.size(); ++i) {
            map[allowed[i] - 'a']++;
        }

        for (const auto& word : words) {
            bool is_consist = true;
            for (const auto& ch : word) {
                if (map[ch - 'a'] == 0) {
                    is_consist = false;
                }
            }
            if (is_consist == true) {
                ++count;
            }
        }

        return count;    
    }

private:
    enum { ALPHABET_SIZE = 26 };
};

// https://leetcode.com/problems/count-the-number-of-consistent-strings/description/
