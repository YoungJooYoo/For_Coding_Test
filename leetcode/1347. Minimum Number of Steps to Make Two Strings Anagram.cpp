class Solution 
{
public:
    int minSteps(const string& s, const string& t) 
    {
        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;
        int count = 0;

        for (const auto& elem : s)
        {
            ++freq_s[elem];
        }
        for (const auto& elem : t)
        {
            ++freq_t[elem];
        }

        // s에 필요한 문자가 t에 부족한 경우, 그 차이만큼 교체 횟수에 추가
        for (const auto& elem : freq_s)
        {
            const char ch = elem.first;
            const int freq_in_s = elem.second;
            const int freq_in_t = freq_t[ch];
            
            // s에 있는 문자 빈도가 t에 있는 빈도보다 많을 경우만 교체 필요
            if (freq_in_s > freq_in_t) 
            {
                count += freq_in_s - freq_in_t;
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

/*

1347. 두 문자열을 아나그램으로 만들기 위한 최소 단계 수

같은 길이의 두 문자열 s와 t가 주어집니다. 한 번의 단계에서 t의 어떤 문자를 선택하여 다른 문자로 교체할 수 있습니다.

t를 s의 아나그램으로 만들기 위한 최소 단계 수를 반환하세요.

아나그램이란 같은 문자를 다른 순서(또는 같은 순서)로 포함하는 문자열입니다.

예제 1:

입력: s = "bab", t = "aba"
출력: 1
설명: t에서 첫 번째 'a'를 'b'로 교체하면, t = "bba"가 되어 s의 아나그램이 됩니다.
예제 2:

입력: s = "leetcode", t = "practice"
출력: 5
설명: t에서 'p', 'r', 'a', 'i', 'c'를 적절한 문자로 교체하여 t를 s의 아나그램으로 만듭니다.
예제 3:

입력: s = "anagram", t = "mangaar"
출력: 0
설명: "anagram"과 "mangaar"는 이미 아나그램입니다.

제한사항:

1 <= s.length <= 5 * 10^4
s.length == t.length
s와 t는 소문자 영어 알파벳으로만 구성됩니다.
*/
