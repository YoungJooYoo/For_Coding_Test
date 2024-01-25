class Solution {
public:
    int findTheLongestBalancedSubstring(const string& s) 
    {
        const size_t LEN = s.size();
        int maxLength = 0;
        int index = 0;

        while (index < LEN) {
            int countZeros = 0;
            int countOnes = 0; 

            // '0'의 개수 세기
            while (index < LEN && s[index] == '0') {
                ++countZeros;
                ++index;
            }
            // '1'의 개수 세기
            while (index < LEN && s[index] == '1') {
                ++countOnes;
                ++index;
            }

            // 균형잡힌 부분 문자열의 길이 계산
            const int currentLength = 2 * min(countZeros, countOnes);
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};

// https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/

/*
### 한국어 번역

이 문제의 정확한 내용이 제공되지 않았기 때문에, 문제의 요점을 가정하여 번역하겠습니다. 가정된 문제 내용은 다음과 같습니다:

"가장 긴 균형잡힌 부분 문자열 찾기":
주어진 문자열 `s`에서 '0'과 '1'이 균형을 이루는 가장 긴 부분 문자열의 길이를 찾으세요. 균형잡힌 부분 문자열이란, '0'과 '1'의 수가 동일한 문자열을 의미합니다.

### 요약

문자열 `s`에서 '0'과 '1'이 같은 개수로 있는 가장 긴 부분 문자열의 길이를 찾는 문제입니다.

### 문제 풀이 방향

1. **두 포인터 또는 슬라이딩 윈도우 방법 사용**: 문자열을 순회하며 '0'과 '1'의 수를 세고, 균형잡힌 상태가 되면 해당 부분 문자열의 길이를 계산합니다.

2. **해시맵 활용**: 각 문자의 출현 빈도를 추적하며 균형잡힌 상태를 확인합니다. 이를 위해 '0'의 수와 '1'의 수의 차이를 키로 사용하는 해시맵을 활용할 수 있습니다.

3. **시간 복잡도 최적화**: O(n) 시간 복잡도를 가지는 효율적인 방법을 찾습니다. 각 문자를 한 번만 순회하며 필요한 정보를 수집합니다.

*/
