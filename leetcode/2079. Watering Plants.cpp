class Solution 
{
public:
    int wateringPlants(const vector<int>& plants, const int capacity) const
    {
        const size_t PLANTS_LENGTH = plants.size();
        int currentCapacity = capacity;
        int result = 0;

        assert(MIN_LEN <= PLANTS_LENGTH && PLANTS_LENGTH <= MAX_LEN);
        assert(MIN_WATER <= capacity && capacity <= MAX_WATER);

        for (size_t i = 0; i < PLANTS_LENGTH; ++i)
        {
            const int need = plants[i];
            assert(MIN_WATER <= need && need <= MAX_WATER);
            assert(need <= capacity); // 문제 조건상 항상 성립
            if (currentCapacity < need)
            {
                result += static_cast<int>(i) * 2; // 강으로 돌아갔다가 다시 오는 왕복 거리
                currentCapacity = capacity;
            }
            ++result; // 식물까지 한 걸음 이동
            currentCapacity -= need;
        }

        assert(result >= 0);
        return result;
    }

private:
    enum
    {
        MIN_LEN = 1,
        MAX_LEN = 1000,
        MIN_WATER = 1,
        MAX_WATER = 1000000000
    };
};

// https://leetcode.com/problems/watering-plants/description/

/*

---

## 💧 2079. 식물 물주기

**난이도: Medium**

당신은 정원에 있는 **n개의 식물**에 물을 주려 합니다.
식물들은 **0번부터 n-1번까지** 왼쪽에서 오른쪽으로 일렬로 놓여 있으며, **i번째 식물은 좌표 x = i**에 있습니다.
좌표 **x = -1**에는 강이 있어서, 물뿌리개를 다시 채울 수 있습니다.

각 식물은 일정량의 물이 필요합니다. 당신은 아래 규칙에 따라 물을 줍니다:

1. 왼쪽에서 오른쪽 순서대로 식물에 물을 준다.
2. 현재 식물에 물을 준 후, 다음 식물을 온전히 물 줄 수 있는 물이 남아있지 않다면 **강(x = -1)으로 돌아가 물뿌리개를 채운다.**
3. 물은 미리 보충할 수 없다.
4. 처음에는 강(x = -1)에서 **가득 찬 물뿌리개**로 시작한다.
5. x축에서 한 칸 움직이는 데 1 걸음이 필요하다.

정수 배열 `plants`가 주어지며, `plants[i]`는 i번째 식물이 필요한 물의 양이다.
정수 `capacity`는 물뿌리개의 최대 용량을 의미한다.

**모든 식물에 물을 주는 데 필요한 걸음 수를 반환하라.**

---

### 예시 1

```
입력: plants = [2,2,3,3], capacity = 5
출력: 14
```

**설명:**

* 처음 위치는 강(-1)이며 물뿌리개는 5 단위로 가득 차 있음.
* 식물 0까지 1 걸음 → 물 주고 남은 물 3.
* 식물 1까지 1 걸음 → 물 주고 남은 물 1.
* 식물 2는 3 단위 필요하지만 남은 물은 1 → 강으로 돌아감 (2 걸음).
* 강에서 채운 뒤, 식물 2까지 3 걸음 → 물 주고 남은 물 2.
* 식물 3은 3 단위 필요하지만 남은 물은 2 → 다시 강으로 돌아감 (3 걸음).
* 강에서 채운 뒤, 식물 3까지 4 걸음 → 물 줌.

총 걸음 수 = 1 + 1 + 2 + 3 + 3 + 4 = **14**

---

### 예시 2

```
입력: plants = [1,1,1,4,2,3], capacity = 4
출력: 30
```

---

### 예시 3

```
입력: plants = [7,7,7,7,7,7,7], capacity = 8
출력: 49
```

---

### 제약 조건

* `n == plants.length`
* `1 <= n <= 1000`
* `1 <= plants[i] <= 10^6`
* `max(plants[i]) <= capacity <= 10^9`

---

*/
