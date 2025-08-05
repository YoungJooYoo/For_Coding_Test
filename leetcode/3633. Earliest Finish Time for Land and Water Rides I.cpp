class Solution
{
public:
    int earliestFinishTime(const vector<int>& landStartTime, const vector<int>& landDuration, const vector<int>& waterStartTime, const vector<int>& waterDuration) const
    {
        assert(landStartTime.size() == landDuration.size());
        assert(waterStartTime.size() == waterDuration.size());

        int minTime = numeric_limits<int>::max();
        const size_t landLength = landStartTime.size();
        const size_t waterLength = waterStartTime.size();

        assert(MIN_LEN <= landLength && landLength <= MAX_LEN);
        assert(MIN_LEN <= waterLength && waterLength <= MAX_LEN);

        // land → water
        for (size_t i = 0; i < landLength; ++i)
        {
            assert(MIN_TIME <= landStartTime[i] && landStartTime[i] <= MAX_TIME);
            assert(MIN_TIME <= landDuration[i] && landDuration[i] <= MAX_TIME);
            const int landFinish = landStartTime[i] + landDuration[i];
            for (size_t j = 0; j < waterLength; ++j)
            {
                assert(MIN_TIME <= waterStartTime[j] && waterStartTime[j] <= MAX_TIME);
                assert(MIN_TIME <= waterDuration[j] && waterDuration[j] <= MAX_TIME);
                const int waterStart = max(waterStartTime[j], landFinish);
                const int finishTime = waterStart + waterDuration[j];
                minTime = min(minTime, finishTime);
            }
        }

        // water → land
        for (size_t i = 0; i < waterLength; ++i)
        {
            assert(MIN_TIME <= waterStartTime[i] && waterStartTime[i] <= MAX_TIME);
            assert(MIN_TIME <= waterDuration[i] && waterDuration[i] <= MAX_TIME);
            const int waterFinish = waterStartTime[i] + waterDuration[i];
            for (size_t j = 0; j < landLength; ++j)
            {
                assert(MIN_TIME <= landStartTime[j] && landStartTime[j] <= MAX_TIME);
                assert(MIN_TIME <= landDuration[j] && landDuration[j] <= MAX_TIME);
                const int landStart = max(landStartTime[j], waterFinish);
                const int finishTime = landStart + landDuration[j];
                minTime = min(minTime, finishTime);
            }
        }

        assert(minTime != numeric_limits<int>::max());
        return minTime;
    }

private:
    enum
    {
        MIN_LEN = 1,
        MAX_LEN = 100,
        MIN_TIME = 1,
        MAX_TIME = 1000
    };
};

// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/

/*

---

## 3633. 육상/수상 놀이기구의 가장 빠른 종료 시간 I

**난이도: 하**

---

### 문제 설명

테마파크의 놀이기구가 **육상 놀이기구**와 **수상 놀이기구** 두 종류로 나누어져 있습니다.

* 육상 놀이기구

  * `landStartTime[i]`: i번째 육상 놀이기구의 **가장 이른 탑승 가능 시간**
  * `landDuration[i]`: i번째 육상 놀이기구의 **운행 시간**

* 수상 놀이기구

  * `waterStartTime[j]`: j번째 수상 놀이기구의 **가장 이른 탑승 가능 시간**
  * `waterDuration[j]`: j번째 수상 놀이기구의 **운행 시간**

여행자는 **각 카테고리에서 각각 하나의 놀이기구만** 타야 하며,
탑승 순서는 자유롭게 정할 수 있습니다.

각 놀이기구는 **오픈 시간 이후 아무 때나** 시작할 수 있습니다.
놀이기구를 t 시점에 탑승하면, 종료 시각은 `t + duration`입니다.

한 놀이기구를 끝내면, 바로 다른 놀이기구를 탈 수 있고,
만약 아직 오픈 전이라면 기다렸다가 탑승합니다.

**두 놀이기구를 모두 끝내는 가장 빠른 시각**을 구해 반환하세요.

---

### 예시

#### 예시 1

**입력:**
landStartTime = \[2,8], landDuration = \[4,1], waterStartTime = \[6], waterDuration = \[3]

**출력:**
9

**설명:**

* **A안**: 육상 0 → 수상 0
  육상 0을 2에 시작해 6에 끝. 수상 0은 6 오픈, 6\~9에 탑승
* **B안**: 수상 0 → 육상 1
  수상 0을 6에 시작해 9에 끝. 육상 1은 8 오픈, 9\~10에 탑승
* **C안**: 육상 1 → 수상 0
  육상 1을 8에 시작해 9에 끝. 수상 0은 6 오픈, 9\~12에 탑승
* **D안**: 수상 0 → 육상 0
  수상 0을 6에 시작해 9에 끝. 육상 0은 2 오픈, 9\~13에 탑승
  가장 빠른 종료는 **9** (A안)

---

#### 예시 2

**입력:**
landStartTime = \[5], landDuration = \[3], waterStartTime = \[1], waterDuration = \[10]

**출력:**
14

**설명:**

* **A안**: 수상 0 → 육상 0
  수상 0을 1에 시작, 11에 끝. 육상 0은 5 오픈, 11\~14에 탑승
* **B안**: 육상 0 → 수상 0
  육상 0을 5에 시작, 8에 끝. 수상 0은 1 오픈, 8\~18에 탑승
  A안이 더 빠르므로 **14**

---

### 제약사항

* 1 <= n, m <= 100
* landStartTime.length == landDuration.length == n
* waterStartTime.length == waterDuration.length == m
* 1 <= landStartTime\[i], landDuration\[i], waterStartTime\[j], waterDuration\[j] <= 1000

---



*/
