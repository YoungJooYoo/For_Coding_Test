class Solution 
{
public:
    vector<int> stableMountains(const vector<int>& height, const int threshold) 
    {
        vector<int> result;
        const size_t LENGTH = height.size();
        
        for (size_t i = 1; i < LENGTH; ++i)
        {
            if (height[i - 1] > threshold)
            {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

/*

3285. 안정적인 산의 인덱스 찾기
**난이도:** 쉬움

**문제 설명:**

일렬로 놓인 `n`개의 산이 있으며, 각 산은 고유한 높이를 가지고 있습니다. 정수 배열 `height`가 주어지며, 여기서 `height[i]`는 `i`번째 산의 높이를 나타냅니다. 또한 정수 `threshold`가 주어집니다.

산은 다음과 같은 조건을 만족할 때 **안정적(stable)**이라고 합니다:

- 해당 산의 바로 앞에 있는 산(존재하는 경우)의 높이가 `threshold`보다 엄격히 큽니다.
- 참고로, 산 `0`은 안정적이지 않습니다.

모든 안정적인 산의 인덱스를 임의의 순서로 담은 배열을 반환하세요.

---

**예제 1:**

```
입력: height = [1,2,3,4,5], threshold = 2
출력: [3,4]
```
**설명:**

- 산 `3`은 안정적입니다. 왜냐하면 `height[2] == 3`이 `threshold == 2`보다 크기 때문입니다.
- 산 `4`도 안정적입니다. 왜냐하면 `height[3] == 4`가 `threshold == 2`보다 크기 때문입니다.

---

**예제 2:**

```
입력: height = [10,1,10,1,10], threshold = 3
출력: [1,3]
```

---

**예제 3:**

```
입력: height = [10,1,10,1,10], threshold = 10
출력: []
```

---

**제약 조건:**

- `2 <= n == height.length <= 100`
- `1 <= height[i] <= 100`
- `1 <= threshold <= 100`

*/
