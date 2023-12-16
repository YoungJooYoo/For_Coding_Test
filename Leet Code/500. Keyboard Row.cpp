class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        const string row[] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> result;

        for (const auto& word : words) {
            for (const auto& keyboard : row) {
                size_t count = 0;
                const size_t LEN =  word.size();
                for (size_t i = 0; i < word.size(); ++i) {
                    if (keyboard.find(word[i]) != string::npos) {
                        ++count;
                        cout << count << endl;
                    }
                }
                if (LEN == count) result.push_back(word);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/keyboard-row/description/
