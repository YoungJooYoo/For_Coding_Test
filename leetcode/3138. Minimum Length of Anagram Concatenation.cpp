class Solution {
public:
    // 두 문자열이 애너그램인지 확인하는 함수
    bool isAnagram(const string& s1, const string& s2) const 
    {
        if (s1.length() != s2.length()) 
        {
            return false;
        }

        unordered_map<char, int> count1;
        unordered_map<char, int> count2;;

        // 첫 번째 문자열의 문자 빈도 계산
        for (char c : s1) 
        {
            count1[c]++;
        }

        // 두 번째 문자열의 문자 빈도 계산
        for (char c : s2) 
        {
            count2[c]++;
        }

        // 두 문자열의 문자 빈도 비교
        return (count1 == count2) ? true : false;
    }
    
    // 모든 겹치지 않는 부분 문자열이 애너그램인지 확인하는 함수
    bool allNonOverlappingSubstringsAreAnagrams(const string& s, const int K) const 
    {
        const string first_sub = s.substr(0, K);

        for (size_t i = 0; i < s.length(); i += K) 
        {
            const string current_sub = s.substr(i, K);
            if (!isAnagram(first_sub, current_sub)) 
            {
                return false;
            }
        }

        return true;
    }
    
    // 주어진 문자열 s의 애너그램 부분 문자열의 최소 길이를 찾는 함수
    int minAnagramLength(const string& s) const 
    {
        const int n = s.size();
        int minLength = n;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                // i가 s의 길이의 약수인 경우
                if (allNonOverlappingSubstringsAreAnagrams(s, i)) 
                {
                    minLength = min(minLength, i);
                }
                // n / i가 s의 길이의 약수인 경우
                if (allNonOverlappingSubstringsAreAnagrams(s, n / i)) 
                {
                    minLength = min(minLength, n / i);
                }
            }
        }

        return minLength;
    }
};

// https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/

/*
## 문제 설명

당신은 문자열 `s`를 받았습니다. 이 문자열 `s`는 어떤 문자열 `t`의 애너그램들의 연결로 이루어져 있습니다.

문자열 `t`의 가능한 최소 길이를 반환하세요.

애너그램은 문자열의 글자 순서를 바꿔서 만들어진 문자열입니다. 예를 들어, "aab", "aba", "baa"는 모두 "aab"의 애너그램입니다.

## 예시

### 예시 1

- 입력: s = "abba"
- 출력: 2
- 설명: 가능한 문자열 `t` 중 하나는 "ba"입니다.

### 예시 2

- 입력: s = "cdef"
- 출력: 4
- 설명: 가능한 문자열 `t` 중 하나는 "cdef"입니다. `t`는 `s`와 같을 수 있습니다.

## 제한 사항

- 1 <= s.length <= 10^5
- s는 소문자 영어 문자로만 이루어져 있습니다.

## 풀이 방향

1. 주어진 문자열 `s`가 애너그램들의 연결로 이루어져 있다는 점을 이용합니다.
2. 문자열 `s`를 통해 문자열 `t`를 찾기 위해 `s`에서 등장하는 모든 문자의 종류와 빈도를 파악합니다.
3. `s`에 등장하는 문자의 종류가 `t`의 최소 길이가 됩니다. 따라서 문자열 `s`에서 고유한 문자의 수를 세어 이를 반환합니다.
*/
