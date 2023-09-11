class Solution {
public:
    string capitalizeTitle(string title) 
    {
        vector<string> words;
        string word;
        stringstream sstream(title);
        string result = "";

        /* tokenize 공백 기준 토큰화, 문자길이에 따라 대소문자 변경 */
        while(getline(sstream, word, ' ')) {
            if (word.size() <= 2) { // 길이가 2보다 작은 경우 전부 소문자
                for (auto& ch : word) {
                    ch = tolower(ch);
                }
                words.push_back(word);
            }
            else { // 맨 앞만 대문자로,
                for (auto& ch : word) {
                    ch = tolower(ch);
                }
                word[0] = toupper(word[0]);
                words.push_back(word);
            }
        }

        /* 토큰화된 문자열들을 이어 붙여서 반환 */
        int count = words.size();
        for (const auto& elem : words) {
            result += elem;
            if (--count > 0) {
                result += " ";
            }
        }

        return result;
    }
};
