class Solution {
public:
    vector<string> generatePalindromes(const string& s) 
    {
        assert(!s.empty() && (MIN_LENGTH <= s.length() && s.length() <= MAX_LENGTH));
    
        unordered_map<char, int> charCount;
        vector<string> permutations;

        for (const char ch : s)
        {
            assert(MIN_CHAR <= ch && ch <= MAX_CHAR);
            ++charCount[ch];
        }

        string halfString;
        char oddChar;
        int  oddCount = 0;

        for (const auto& [ch, count] : charCount)
        {
            if (count % 2 == 1)
            {
                oddChar = ch;
                ++oddCount;
            }
            halfString += string(count / 2, ch);
        }
        
        if (oddCount > 1)
        {
            return permutations; 
        }

        sort(halfString.begin(), halfString.end());
        bool hasNext = true;
        while(hasNext == true)
        {
            hasNext = next_permutation(halfString.begin(), halfString.end());
            string palindrome = halfString;
            if (oddCount == 1)
            {
                palindrome += oddChar;
            }
            palindrome += string(halfString.rbegin(), halfString.rend());
            permutations.push_back(palindrome);
        }

        assert(permutations.size() > 0);
        return permutations;
    }

private:
    enum  
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 16,
        MIN_CHAR = 'a',
        MAX_CHAR = 'z'
    };
};


// https://leetcode.com/problems/palindrome-permutation-ii/description/

/*

문제 설명
주어진 문자열 s에서 모든 **회문 순열(Palindromic Permutations)**을 반환하세요.
결과는 중복 없이 반환해야 하며, 순서는 상관없습니다.
만약 s로 회문 순열을 만들 수 없다면 빈 리스트를 반환하세요.

예제
예제 1:

입력: s = "aabb"
출력: ["abba","baab"]
예제 2:

입력: s = "abc"
출력: []
제약 조건
1
≤
s.length
≤
16
1≤s.length≤16
𝑠
s는 소문자 영어 알파벳으로만 구성됩니다.
변경된 코드 설명
assert를 통한 입력 검증:

문자열 길이와 문자 조건을 익명 enum으로 정의한 범위 내인지 검증합니다.
익명 enum을 통한 매직 넘버 제거:

제약 조건을 Limits 익명 enum으로 관리합니다.
변수에 const 추가:

함수 내 변동되지 않는 모든 변수에 const를 추가했습니다.
로직:

문자 빈도를 계산하여 가능한 회문 구성 여부를 확인합니다.
짝수 개수로 나눠진 절반 문자열을 조합하여 모든 가능한 회문을 생성합니다.

*/
