class Solution 
{
public:
    int findTheLongestSubstring(const string& s) 
    {
        unordered_map<int, int> stateIndexMap; // 비트마스크 상태를 처음으로 만났을 때의 인덱스를 저장합니다.
        stateIndexMap[0] = -1;  // 초기 상태: 모든 모음의 개수가 짝수인 상태
        int maxLength = 0;
        int state = 0;  // 현재 상태를 나타내는 비트마스크

        for (size_t i = 0; i < s.size(); ++i) 
        {
            switch (s[i]) // 현재 문자가 모음이면 비트마스크 상태를 변경합니다.
            {
                case 'a':
                    state ^= 1 << 0;  // 첫 번째 비트 토글
                    break;
                case 'e':
                    state ^= 1 << 1;  // 두 번째 비트 토글
                    break;
                case 'i':
                    state ^= 1 << 2;  // 세 번째 비트 토글
                    break;
                case 'o':
                    state ^= 1 << 3;  // 네 번째 비트 토글
                    break;
                case 'u':
                    state ^= 1 << 4;  // 다섯 번째 비트 토글
                    break;
            }
            
            // 현재 상태가 이전에 등장한 적이 있는지 확인합니다.
            if (stateIndexMap.find(state) != stateIndexMap.end()) 
            {
                // 동일한 상태가 등장했다면, 그 사이의 부분 문자열은 유효합니다.
                maxLength = max(maxLength, static_cast<int>(i) - stateIndexMap[state]);
            }
            else 
            {
                stateIndexMap[state] = i; // 현재 상태가 처음 등장하면 그 인덱스를 저장합니다.
            }
        }

        return maxLength;
    }
};


// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
/*
**1371. 짝수 개의 모음을 포함하는 가장 긴 부분 문자열 찾기**

난이도: 중간

**문제 설명**  
문자열 `s`가 주어질 때, 각 모음이 짝수 개씩 포함된 가장 긴 부분 문자열의 길이를 반환하세요. 
여기서 모음은 'a', 'e', 'i', 'o', 'u'를 의미하며, 이들 각 문자가 짝수 개씩 나타나야 합니다.

**예제**

- 예제 1:
  - 입력: `s = "eleetminicoworoep"`
  - 출력: `13`
  - 설명: 가장 긴 부분 문자열은 `"leetminicowor"`이며, 모음 `e`, `i`, `o`가 각각 두 개씩 포함되어 있고, 모음 `a`, `u`는 나타나지 않습니다.

- 예제 2:
  - 입력: `s = "leetcodeisgreat"`
  - 출력: `5`
  - 설명: 가장 긴 부분 문자열은 `"leetc"`이며, 모음 `e`가 두 번 나타납니다.

- 예제 3:
  - 입력: `s = "bcbcbc"`
  - 출력: `6`
  - 설명: 이 경우, 주어진 문자열 `"bcbcbc"`가 가장 길며, 모든 모음 `a`, `e`, `i`, `o`, `u`가 각각 0번 나타납니다.

**제약 사항**  
- 1 <= `s.length` <= 5 × 10^5
*/

