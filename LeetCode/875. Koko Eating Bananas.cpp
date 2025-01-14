class Solution 
{
public:
    int minEatingSpeed(const vector<int>& piles, const int h) 
    {
        // 제약 조건 검증
        assert(piles.size() >= MIN_PILES_LENGTH && piles.size() <= MAX_PILES_LENGTH);
        assert(h >= piles.size() && h <= MAX_HOURS);

        return binarySearchMinSpeed(piles, h);
    }

private:
    int binarySearchMinSpeed(const vector<int>& piles, const int h) const  // 이진 탐색을 수행하여 최소 속도를 찾음
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) 
        {
            const int mid = left + (right - left) / 2;
            if (canEatAll(piles, h, mid) == true)   // 현재 속도로 가능하다면 결과를 갱신하고 탐색 범위를 줄임
            {
                result = mid;
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }

        return result;
    }

    bool canEatAll(const vector<int>& piles, const int h, const int k) const 
    {
        int hoursNeeded = 0;

        for (const int pile : piles) 
        {
            assert(pile >= MIN_PILE_SIZE && pile <= MAX_PILE_SIZE);
            assert(pile + k - 1 >= 0);
            hoursNeeded += (pile + k - 1) / k; // 올림 계산: ⌈pile / k⌉
            if (hoursNeeded > h) 
            {
                return false; // 시간 초과
            }
        }

        return true;
    }


private:
    int mResult = 0;

    enum 
    {
        MIN_PILES_LENGTH = 1,
        MAX_PILES_LENGTH = 10000,

        MIN_PILE_SIZE = 1,
        MAX_PILE_SIZE = 1000000000, // 10^9

        MAX_HOURS = 1000000000      // 10^9
    };
};

// https://leetcode.com/problems/koko-eating-bananas/

/*
### **875. 코코가 바나나를 먹는 속도**

**난이도**: Medium

---

### **문제 설명**

코코는 바나나를 먹는 것을 좋아합니다. \( n \)개의 바나나 더미가 있으며, \( i \)번째 더미에는 \( \text{piles}[i] \)개의 바나나가 있습니다. 현재 경비원들이 자리를 비웠고, \( h \)시간 후에 돌아올 예정입니다.

코코는 바나나를 먹는 속도 \( k \)(시간당 바나나 수)를 결정할 수 있습니다. 각 시간마다 다음과 같이 행동합니다:
1. 특정 바나나 더미를 선택하여 \( k \)개의 바나나를 먹습니다.
2. 만약 해당 더미에 남아 있는 바나나가 \( k \)보다 적다면, 남아 있는 모든 바나나를 먹고 그 시간은 끝납니다.
3. 한 시간 동안 하나의 더미에서만 바나나를 먹습니다.

코코는 천천히 먹는 것을 좋아하지만, **모든 바나나를 경비원이 돌아오기 전에 먹어야 합니다**.

**문제**: 코코가 \( h \)시간 이내에 모든 바나나를 먹을 수 있는 최소 속도 \( k \)를 반환하세요.

---

### **입출력 예시**

#### **예제 1**
- **입력**:
  ```text
  piles = [3,6,7,11], h = 8
  ```
- **출력**:
  ```text
  4
  ```
- **설명**:
  - \( k = 4 \)일 때:
    1. 1시간 동안 첫 번째 더미에서 3개 모두 먹음.
    2. 두 번째 더미에서 4개 먹고 남은 2개는 1시간 더 사용.
    3. 세 번째 더미에서 4개 먹고 남은 3개는 1시간 더 사용.
    4. 네 번째 더미에서 4개 먹고 남은 7개는 2시간 더 사용.
    - 총 8시간이 걸립니다.

---

#### **예제 2**
- **입력**:
  ```text
  piles = [30,11,23,4,20], h = 5
  ```
- **출력**:
  ```text
  30
  ```
- **설명**:
  - \( k = 30 \)이어야 5시간 안에 모든 바나나를 먹을 수 있습니다.

---

#### **예제 3**
- **입력**:
  ```text
  piles = [30,11,23,4,20], h = 6
  ```
- **출력**:
  ```text
  23
  ```

---

### **제약 조건**
1. \( 1 \leq \text{piles.length} \leq 10^4 \)
2. \( \text{piles.length} \leq h \leq 10^9 \)
3. \( 1 \leq \text{piles}[i] \leq 10^9 \)

---

### **힌트**
1. 이진 탐색을 사용하여 \( k \)의 최소값을 효율적으로 찾을 수 있습니다.
2. 각 \( k \)에 대해 \( h \)시간 이내에 모든 바나나를 먹을 수 있는지 확인하는 함수가 필요합니다.
*/
