class Solution 
{
public:
    vector<int> toggleLightBulbs(const vector<int>& bulbs) const 
    {
        assert(MIN_BULBS_LENGTH <= bulbs.size() && bulbs.size() <= MAX_BULBS_LENGTH);

        unordered_map<int, int> freq;
        vector<int> result;

        for (const auto bulb : bulbs)
        {
            assert(MIN_BULB <= bulb && bulb <= MAX_BULB);
            ++freq[bulb];
        }

        for (const auto [bulb, count] : freq)
        {
            if (count % 2 == 1)
            {
                result.push_back(bulb);
            }
        }

        ranges::sort(result);
        return result;
    }

private:
    enum
    {
        MIN_BULBS_LENGTH = 1,
        MAX_BULBS_LENGTH = 100,
        MIN_BULB = 1,
        MAX_BULB = 100,
    };
};

/*
https://leetcode.com/problems/toggle-light-bulbs/description/

### 3842. 전구 토글 (Toggle Light Bulbs)

**문제 설명**  
1부터 100 사이의 정수로 이루어진 배열 `bulbs`가 주어집니다.

1부터 100까지 번호가 매겨진 100개의 전구가 있으며, 처음에는 모두 꺼져 있습니다.

배열 `bulbs`의 각 요소 `bulbs[i]`에 대해 다음과 같은 작업을 수행합니다:

1. 만약 `bulbs[i]`번째 전구가 현재 **꺼져 있다면**, 켭니다.
2. 만약 **켜져 있다면**, 끕니다.

작업이 모두 끝난 후 **켜져 있는 전구들의 번호**를 오름차순으로 정렬한 정수 리스트를 반환하세요. 만약 켜진 전구가 하나도 없다면 빈 리스트를 반환합니다.

**예시 1:**
*   **입력:** `bulbs = [10, 30, 20, 10]`
*   **출력:** `[20, 30]`
*   **설명:**
    1. `bulbs[0] = 10`: 10번 전구가 꺼져 있으므로 킵니다. (10번 ON)
    2. `bulbs[1] = 30`: 30번 전구가 꺼져 있으므로 킵니다. (30번 ON)
    3. `bulbs[2] = 20`: 20번 전구가 꺼져 있으므로 킵니다. (20번 ON)
    4. `bulbs[3] = 10`: 10번 전구가 켜져 있으므로 끕니다. (10번 OFF)
    *   결과: 20번과 30번 전구만 켜져 있습니다.

**예시 2:**
*   **입력:** `bulbs = [100, 100]`
*   **출력:** `[]`
*   **설명:**
    1. `bulbs[0] = 100`: 100번 전구가 꺼져 있으므로 킵니다. (100번 ON)
    2. `bulbs[1] = 100`: 100번 전구가 켜져 있으므로 끕니다. (100번 OFF)
    *   결과: 켜진 전구가 없습니다.

**제약 사항:**
*   `1 <= bulbs.length <= 100`
*   `1 <= bulbs[i] <= 100`

---

**힌트:**
*   전구의 상태(켜짐/꺼짐)를 추적하는 가장 간단한 방법은 무엇일까요?
*   각 작업은 단순히 현재 상태를 **반전(toggle)**시키는 것입니다.
*   최종적으로 `bulbs` 배열을 처음부터 끝까지 순회한 후, 상태가 "켜짐"인 전구들만 선택하면 됩니다.
*/
