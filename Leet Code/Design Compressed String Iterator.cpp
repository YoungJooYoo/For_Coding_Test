class StringIterator {
public:
    StringIterator(const string& s) 
    {
        int index = 0; // 현재 처리 중인 문자열의 위치

        while (index < s.size()) {
            char currentChar = s[index++]; // 현재 문자 저장 및 인덱스 증가
            int count = 0; // 현재 문자의 반복 횟수

            // 숫자 파싱: 반복 횟수 계산
            while (index < s.size() && isdigit(s[index])) {
                count = count * 10 + (s[index] - '0');
                ++index;
            }

            // 문자와 반복 횟수를 큐에 추가
            charQueue.push({currentChar, count});
        }
    }

    // 다음 문자를 반환하는 메서드
    char next() {
        if (hasNext()) {
            pair<char, int>& frontPair = charQueue.front(); // 큐의 맨 앞 요소 참조

            // 반환할 문자 저장 및 해당 문자의 반복 횟수 감소
            const char nextChar = frontPair.first;
            frontPair.second--;

            // 반복 횟수가 0이 되면, 큐에서 해당 요소 제거
            if (frontPair.second == 0) {
                charQueue.pop();
            }

            return nextChar;
        } else {
            return ' '; // 다음 문자가 없으면 공백 반환
        }
    }

    // 큐가 비어있지 않으면 다음 문자가 있음
    bool hasNext() {
        return !charQueue.empty();
    }

private:  
    queue<pair<char, int>> charQueue; // 문자와 해당 문자의 반복 횟수를 저장하는 큐
};

// https://leetcode.com/problems/design-compressed-string-iterator/description/
