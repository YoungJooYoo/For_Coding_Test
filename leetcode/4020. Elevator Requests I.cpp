class Solution
{
public:
    int elevatorRequests(const int n, const vector<int>& requests)
    {
        assert(MIN_FLOOR_COUNT <= n && n <= MAX_FLOOR_COUNT);
        assert(MIN_LENGTH <= requests.size() && requests.size() <= MAX_LENGTH);

        const size_t LENGTH = requests.size();
        int sum = requests[0];

        for (size_t i = 0; i < LENGTH - 1; ++i)
        {
            assert(0 <= requests[i] && requests[i] <= n - 1);
            assert(0 <= requests[i + 1] && requests[i + 1] <= n - 1);
            const int currentTime = abs(requests[i + 1] - requests[i]);
            sum += currentTime;
        }

        assert(sum >= 0);
        return sum;
    }

private:
    enum
    {
        MIN_FLOOR_COUNT = 1,
        MAX_FLOOR_COUNT = 100,
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};

/*
https://leetcode.com/problems/elevator-requests-i/description/

## 4020. 엘리베이터 요청 I (Elevator Requests I)

**난이도: Easy**

건물의 층 수를 나타내는 정수 `n`이 주어지며, 층은 0부터 `n - 1`까지 번호가 매겨져 있습니다.

또한 층 요청 순서를 나타내는 정수 배열 `requests`가 주어집니다.

엘리베이터는 0층에서 출발하며, 다음 규칙을 따릅니다:

- 엘리베이터는 초당 한 층씩 이동합니다.
- 엘리베이터는 주어진 순서대로 요청을 처리합니다.
- 엘리베이터가 이미 요청된 층에 있다면, 이동이 필요 없습니다.
- 하나의 요청을 처리한 후, 엘리베이터는 즉시 다음 요청을 향해 이동하기 시작합니다.

모든 요청을 처리하는 데 필요한 총 시간(초)을 반환하세요.

---

**예제 1:**
```
입력: n = 5, requests = [2,1,4,3]
출력: 7
설명:

- requests[0] = 2: 0층에서 2층으로 이동하는 데 2초가 걸립니다.
- requests[1] = 1: 2층에서 1층으로 이동하는 데 1초가 걸립니다.
- requests[2] = 4: 1층에서 4층으로 이동하는 데 3초가 걸립니다.
- requests[3] = 3: 4층에서 3층으로 이동하는 데 1초가 걸립니다.

필요한 총 시간은 2 + 1 + 3 + 1 = 7초입니다.
```

**예제 2:**
```
입력: n = 3, requests = [2,0,0]
출력: 4
설명:

- requests[0] = 2: 0층에서 2층으로 이동하는 데 2초가 걸립니다.
- requests[1] = 0: 2층에서 0층으로 이동하는 데 2초가 걸립니다.
- requests[2] = 0: 이동이 필요 없습니다.

필요한 총 시간은 2 + 2 + 0 = 4초입니다.
```

---

**제약 조건:**
- `1 <= n <= 100`
- `1 <= requests.length <= 100`
- `0 <= requests[i] <= n - 1`
*/
