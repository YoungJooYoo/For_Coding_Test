class Solution 
{
public:
    int numTeams(const vector<int>& rating) 
    {
        const size_t totalSoldiers = rating.size();
        int validTeamCount = 0;

        assert(MIN_RATING_LENGTH <= totalSoldiers && totalSoldiers <= MAX_RATING_LENGTH);

        for (size_t current = 0; current < totalSoldiers; ++current)
        {
            int leftSmaller = 0; 
            int leftGreater = 0;
            int rightSmaller = 0;
            int rightGreater = 0;

            // 왼쪽에 있는 병사들 계산
            for (size_t left = 0; left < current; ++left)
            {
                if (rating[left] < rating[current])
                {
                    ++leftSmaller;
                }
                else if (rating[left] > rating[current])
                {
                    ++leftGreater;
                }
            }

            // 오른쪽에 있는 병사들 계산
            for (size_t right = current + 1; right < totalSoldiers; ++right)
            {
                if (rating[right] < rating[current])
                {
                    ++rightSmaller;
                }
                else if (rating[right] > rating[current])
                {
                    ++rightGreater;
                }
            }

            validTeamCount += (leftSmaller * rightGreater) + (leftGreater * rightSmaller); // 증가하는 팀 + 감소하는 팀
        }

        return validTeamCount;
    }

private:
    enum
    {
        MIN_RATING_LENGTH = 3,
        MAX_RATING_LENGTH = 1000,
    };
};


// https://leetcode.com/problems/count-number-of-teams/description

/*
**1395. 팀의 수를 세기**  
**난이도**: Medium  

---

### 문제 설명

일렬로 서 있는 \(n\)명의 병사가 있습니다. 각 병사에게는 고유한 평가 값(`rating`)이 할당되어 있습니다.  

다음 규칙을 충족하며, 세 명의 병사로 이루어진 팀을 구성해야 합니다:  

1. 세 명의 병사 \(i, j, k\)를 선택합니다 (\(0 \leq i < j < k < n\)).
2. 이 팀은 다음 조건 중 하나를 만족해야 합니다:
   - \(rating[i] < rating[j] < rating[k]\): 평가 값이 엄격히 증가하는 경우.
   - \(rating[i] > rating[j] > rating[k]\): 평가 값이 엄격히 감소하는 경우.

위 조건을 만족하는 팀의 개수를 반환하세요. (병사는 여러 팀에 포함될 수 있습니다.)

---

### 예제

**예제 1**:  
- **입력**:  
  ```text
  rating = [2,5,3,4,1]
  ```
- **출력**:  
  ```text
  3
  ```
- **설명**:  
  조건을 만족하는 세 팀은 다음과 같습니다:  
  - (2,3,4)  
  - (5,4,1)  
  - (5,3,1)  

---

**예제 2**:  
- **입력**:  
  ```text
  rating = [2,1,3]
  ```
- **출력**:  
  ```text
  0
  ```
- **설명**:  
  조건을 만족하는 팀을 구성할 수 없습니다.  

---

**예제 3**:  
- **입력**:  
  ```text
  rating = [1,2,3,4]
  ```
- **출력**:  
  ```text
  4
  ```
- **설명**:  
  조건을 만족하는 팀은 다음과 같습니다:  
  - (1,2,3)  
  - (1,2,4)  
  - (1,3,4)  
  - (2,3,4)  

---

### 제약 조건
1. \(n = rating.length\)  
2. \(3 \leq n \leq 1000\)  
3. \(1 \leq rating[i] \leq 10^5\)  
4. `rating`의 모든 정수는 고유합니다.  

---

### 문제 풀이 힌트
- 병사의 수가 최대 1000명까지 가능하므로, \(O(n^3)\) 복잡도의 완전 탐색은 적절하지 않을 수 있습니다.
- **병사를 기준으로 왼쪽/오른쪽의 작은 값 또는 큰 값을 세는 방식**으로 효율적으로 계산할 수 있습니다.
- 증가하는 경우와 감소하는 경우를 각각 독립적으로 계산한 후 더합니다.  
*/
