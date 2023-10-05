class Solution {
public:
    bool areAlmostEqual(string& s1, string& s2) 
    {
        const size_t LEN = s1.size();
        int count = 0;
        map<char, int> str1;
        map<char, int> str2;

        for (size_t i = 0; i < LEN;++i) { // 해시테이블에 넣어 두 문자열의 원소가 동일하게 구성되었는지확인
            ++str1[s1[i]];
            ++str2[s2[i]];
        }
        
        if  (str1 != str2) { // 해시테이블에 넣어 두 문자열의 원소가 동일하게 구성되었는지확인
            return false;
        }

        // 두 문자열을 이룬 원소가 같다는 조건 확인후, 위치가 2번 초과하여 달라지면 false
        for (size_t i = 0; i < LEN; ++i) {
            if (s1[i] != s2[i]) {
                ++count;
            }
            if (count >= 3) {
                return false;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/
