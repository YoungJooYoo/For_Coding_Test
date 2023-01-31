class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int max_count = 1;

        for (const auto& word : sentences) {
            int count = 1;
            for (const auto& ch : word) {
                if (ch == ' ') {
                    count++;
                }
            }
            max_count = max(max_count, count);
        }

        return max_count;    
    }
};

/*
공백 + 1이 총 문자열의 갯수가 될 수 있다.
공백이 없다면, 단어가 1개이다.
*/

// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/
