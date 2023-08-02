class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) 
    {
        vector<vector<int>> result;

        for (const auto& word : words) {
            int pos = text.find(word);
            while (pos != string::npos) {
                result.push_back({pos, pos + (int)word.size() - 1}); // 시작점, 시작점 + 단어길이  묶음으로 배열에 집어 넣는다.
                pos = text.find(word, pos + 1); // 다음 탐색 위치는, 탐색된 위치 pos + 1 그 다음부터 다시 검색한다.
            }
        }   

        sort(result.begin(), result.end());
        
        return result;
    }
};

// https://leetcode.com/problems/index-pairs-of-a-string/description/
