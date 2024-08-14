class Solution {
public:
    int closetTarget(const vector<string>& words, const string& target, const int startIndex) 
    {
        const size_t LENGTH = words.size();
        int min_distance = numeric_limits<int>::max();

        for (int i = 0; i < LENGTH; ++i)
        {
            if (words[i] == target)
            {
                int distance = abs(startIndex - i);
                distance = min(distance, static_cast<int>(LENGTH - distance));  // 반대 방향으로 가는 거리도 고려
                min_distance = min(min_distance, distance);
            }
        }

        return (min_distance == INT_MAX) ? FAIL : min_distance;
    }
private:
    enum { FAIL = -1 };
};

// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/


/*
### 문제 번역:

당신은 `words`라는 0-인덱스 원형 문자열 배열과 문자열 `target`을 가지고 있습니다. 원형 배열이란 배열의 끝이 배열의 시작과 연결된다는 의미입니다.

공식적으로, `words[i]`의 다음 요소는 `words[(i + 1) % n]`이고, 이전 요소는 `words[(i - 1 + n) % n]`입니다. 여기서 `n`은 `words`의 길이입니다.

`startIndex`에서 시작하여, 다음 단어 또는 이전 단어로 한 번에 1단계씩 이동할 수 있습니다.

`target` 문자열에 도달하기 위해 필요한 최단 거리를 반환하세요. 만약 `target` 문자열이 `words`에 존재하지 않는다면 -1을 반환하세요.

### 예시:

**예시 1:**
- 입력: `words = ["hello","i","am","leetcode","hello"]`, `target = "hello"`, `startIndex = 1`
- 출력: `1`
- 설명:
  - 인덱스 1에서 시작하여 `hello`에 도달하기 위해 다음과 같은 방법이 있습니다:
    - 오른쪽으로 3번 이동하여 인덱스 4에 도달합니다.
    - 왼쪽으로 2번 이동하여 인덱스 4에 도달합니다.
    - 오른쪽으로 4번 이동하여 인덱스 0에 도달합니다.
    - 왼쪽으로 1번 이동하여 인덱스 0에 도달합니다.
  - `hello`에 도달하는 최단 거리는 1입니다.

**예시 2:**
- 입력: `words = ["a","b","leetcode"]`, `target = "leetcode"`, `startIndex = 0`
- 출력: `1`
- 설명:
  - 인덱스 0에서 시작하여 `leetcode`에 도달하기 위해 다음과 같은 방법이 있습니다:
    - 오른쪽으로 2번 이동하여 인덱스 2에 도달합니다.
    - 왼쪽으로 1번 이동하여 인덱스 2에 도달합니다.
  - `leetcode`에 도달하는 최단 거리는 1입니다.

**예시 3:**
- 입력: `words = ["i","eat","leetcode"]`, `target = "ate"`, `startIndex = 0`
- 출력: `-1`
- 설명:
  - `ate`는 `words`에 존재하지 않으므로 -1을 반환합니다.

### 제약 조건:
- `1 <= words.length <= 100`
- `1 <= words[i].length <= 100`
- `words[i]`와 `target`은 소문자 영어 알파벳으로만 구성됩니다.
- `0 <= startIndex < words.length`

### 문제 해결 접근법:

1. **문자열 탐색**: `startIndex`를 기준으로 양쪽(왼쪽과 오른쪽)으로 문자열을 탐색합니다.
2. **양방향 이동**: 오른쪽으로 이동할 때와 왼쪽으로 이동할 때의 거리를 각각 계산합니다.
3. **최단 거리 선택**: 각 방향에서 `target`을 찾는 데 필요한 거리를 비교하여 최단 거리를 반환합니다.
4. **존재 여부 확인**: 만약 `target`이 `words` 배열에 없다면, -1을 반환합니다.

*/
