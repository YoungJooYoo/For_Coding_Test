class Solution 
{
public:
    long long findScore(vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        long long sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 인덱스를 저장하는 priority_queue, 값이 작은 순으로 처리

        for (size_t i = 0; i < LENGTH; ++i)
        {
            pq.push({nums[i], i}); // 우선순위 큐에 (값, 인덱스) 쌍을 넣는다.
        }

        while (!pq.empty())
        {
            const int value = pq.top().first;
            const int index = pq.top().second;
            pq.pop();

            if (nums[index] != MARKING) // 이미 MARKING된 인덱스는 건너뛴다.
            {
                sum += value; // 값 누적 및 현재 인덱스와 양 옆 인덱스 MARKING
                nums[index] = MARKING;

                if (index - 1 >= 0) 
                {
                    nums[index - 1] = MARKING;
                }
                if (index + 1 < LENGTH) 
                {
                    nums[index + 1] = MARKING;
                }
            }
        }

        return sum;
    }

private:
    enum { MARKING = -1 };
};

// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13

/*
### **2593. 모든 요소를 마킹한 후 배열의 점수 찾기**

---

### **문제 설명**  
양의 정수로 이루어진 배열 `nums`가 주어집니다.

초기 점수 `score = 0`에서 시작하여 다음 알고리즘을 적용합니다:  

1. 배열에서 마킹되지 않은 가장 작은 정수를 선택합니다. 만약 동점이 있으면 **가장 왼쪽에 있는** 정수를 선택합니다.  
2. 선택된 정수의 값을 **score**에 더합니다.  
3. 선택된 요소와 그 **양 옆의 인접한 요소들**(존재하는 경우)을 마킹합니다.  
4. 위 과정을 **모든 배열의 요소가 마킹될 때까지** 반복합니다.  

위 알고리즘을 적용한 후 최종적으로 얻은 점수를 반환하세요.  

---

### **예제**

**예제 1**:  
**입력**: `nums = [2,1,3,4,5,2]`  
**출력**: `7`  

**설명**:  
마킹 과정을 다음과 같이 수행합니다:  
- `1`이 마킹되지 않은 가장 작은 요소이므로 선택하고, 왼쪽과 오른쪽의 인접 요소를 마킹합니다.  
- 배열 상태: `[2,1,3,4,5,2]`  
- `2`가 마킹되지 않은 가장 작은 요소이므로 선택하고, 왼쪽 인접 요소를 마킹합니다.  
- 배열 상태: `[2,1,3,4,5,2]`  
- `4`만 남은 마킹되지 않은 요소이므로 선택하고 마킹합니다.  
- 배열 상태: `[2,1,3,4,5,2]`  

점수는 `1 + 2 + 4 = 7`입니다.  

---

**예제 2**:  
**입력**: `nums = [2,3,5,1,3,2]`  
**출력**: `5`  

**설명**:  
마킹 과정을 다음과 같이 수행합니다:  
- `1`이 가장 작은 요소이므로 선택하고 양옆의 인접 요소를 마킹합니다.  
- 배열 상태: `[2,3,5,1,3,2]`  
- 두 개의 `2` 중에서 가장 왼쪽의 요소를 선택하고, 오른쪽 인접 요소를 마킹합니다.  
- 배열 상태: `[2,3,5,1,3,2]`  
- 남은 유일한 `2`를 선택하고 마킹합니다.  
- 배열 상태: `[2,3,5,1,3,2]`  

점수는 `1 + 2 + 2 = 5`입니다.  

---

### **제약 조건**
- \( 1 \leq nums.length \leq 10^5 \)  
- \( 1 \leq nums[i] \leq 10^5 \)  

--- 

### **힌트**  
- 우선순위 큐 또는 정렬된 순서로 값을 관리하면 효율적으로 마킹할 수 있습니다.  
- 최소 값을 빠르게 찾는 자료구조를 사용하면 성능을 개선할 수 있습니다.
*/
