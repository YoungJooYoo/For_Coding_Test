class Solution {
public:
    string greatestLetter(const string& s) 
    {
        set<char> lower;
        set<char> upper;
        string result = ""; // 결과를 저장할 문자열, 기본값은 빈 문자열
        char greatest_letter = 0; // 초기화하지 않으면 무작위 값이 할당될 수 있음

        for (const auto& ch : s) {
            if (islower(ch)) {
                lower.insert(ch);
            } else { // upper case
                upper.insert(ch);
            }
        }

        for (const auto& ch : upper) {
            // 대문자를 소문자로 변환하여 소문자 집합에 존재하는지 확인
            if (lower.find(tolower(ch)) != lower.end()) {
                // 알파벳 순으로 가장 큰 문자를 찾기 위해 비교
                if (greatest_letter != 0 || ch > greatest_letter) {
                    greatest_letter = ch;
                }
            }
        }

        // greatest_letter가 설정되었는지 확인
        if (greatest_letter != 0) {
            result.push_back(greatest_letter);
        }

        return result;
    }
};

// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/
