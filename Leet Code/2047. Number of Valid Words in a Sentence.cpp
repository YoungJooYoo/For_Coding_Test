class Solution {
public:
    bool solve(const string& word) 
    {
        const size_t LEN = word.size();
        int hyp_count = 0;

        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i]) == true) return false;
            else if (isalpha(word[i])) continue;
            else if (word[i] == '-') {
                const size_t FIRST_IDX = 0;
                const size_t LAST_IDX = LEN - 1;
                hyp_count++;
                if (hyp_count > 1 || i == FIRST_IDX || i  == LAST_IDX || !isalpha(word[i - 1]) || !isalpha(word[i + 1])) return false;
            }
            else if (i != LEN - 1) return false;
        }
        return true;
    }

    int countValidWords(const string& sentence) 
    {
        stringstream s(sentence);
        string word;
        int count = 0;

        while (s >> word) {
            if (solve(word) == true) ++count;
        }

        return count;
    }
};

// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/
