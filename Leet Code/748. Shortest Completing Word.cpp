class Solution {
public:
    string shortestCompletingWord(const string& licensePlate, const vector<string>& words) 
    {
        vector<int> freq(ALPHA_LEN, 0); // 알파벳별 빈도수 저장
        for (const char& ch : licensePlate) {
            if (isalpha(ch)) {
                ++freq[tolower(ch) - 'a'];
            }
        }

        string result = "";
        for (const string& word : words) {
            vector<int> wordFreq(ALPHA_LEN, 0);
            for (const char ch : word) {
                ++wordFreq[ch - 'a'];
            }

            bool b_isValid = true;
            for (int i = 0; i < ALPHA_LEN; ++i) {
                if (freq[i] > 0 && wordFreq[i] < freq[i]) { //licesepalte에 존재하하지만, word에 모자란경우
                    b_isValid = false;
                    break;
                }
            }

            if (b_isValid && (result.empty() || word.size() < result.size())) {
                result = word;
            }
        }

        return result;
    }
private:
    enum { ALPHA_LEN  = 26 };
};

// https://leetcode.com/problems/shortest-completing-word/description/
