class Solution 
{
public:
    int maxWidthRamp(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        vector<int> stack; // 단조 감소 스택 (인덱스 저장)
        int maxWidth = 0;
        
        // 1. 단조 감소 스택 구성
        stack.push_back(0);
        for (size_t i = 0; i < LENGTH; ++i) 
        {
            if (nums[stack.back()] > nums[i]) 
            {
                stack.push_back(i);
            }
        }

        // 2. 역방향으로 순회하며 최대 너비 계산
        for (int j = static_cast<int>(LENGTH) - 1; j > 0; --j ) 
        {
            while (!stack.empty() && nums[stack.back()] <= nums[j]) 
            {
                const int i = stack.back();
                stack.pop_back();
                const int currWidth = j - i;
                assert(currWidth >= 0);
                maxWidth = max(maxWidth, currWidth);         
            }
        }

        return maxWidth;
    }
};

// https://leetcode.com/problems/maximum-width-ramp/description/

/*
### 문제 번역

**962. 최대 너비 램프**

**문제 설명**  
정수 배열 `nums`에서 램프(ramp)는 다음 조건을 만족하는 `(i, j)` 쌍을 의미합니다:  
- \( i < j \)  
- \( nums[i] \leq nums[j] \)  

램프의 **너비**는 \( j - i \)입니다.

정수 배열 `nums`가 주어졌을 때, 배열에서 가능한 램프의 **최대 너비**를 반환하세요. 만약 램프가 존재하지 않는다면 `0`을 반환하세요.

---

**입력 및 출력 예제**

- **예제 1**:  
  입력: `nums = [6,0,8,2,1,5]`  
  출력: `4`  
  설명: 최대 너비 램프는 \((i, j) = (1, 5)\)에서 이루어집니다. \( nums[1] = 0 \), \( nums[5] = 5 \)이고 너비는 \( 5 - 1 = 4 \)입니다.

- **예제 2**:  
  입력: `nums = [9,8,1,0,1,9,4,0,4,1]`  
  출력: `7`  
  설명: 최대 너비 램프는 \((i, j) = (2, 9)\)에서 이루어집니다. \( nums[2] = 1 \), \( nums[9] = 1 \)이고 너비는 \( 9 - 2 = 7 \)입니다.

---

**제약 조건**

- \( 2 \leq nums.length \leq 5 \times 10^4 \)
- \( 0 \leq nums[i] \leq 5 \times 10^4 \)

---

### 문제 풀이 전략

1. **브루트 포스 접근**  
   - 모든 \((i, j)\) 쌍을 탐색하며 \( nums[i] \leq nums[j] \)인 경우의 최대 너비를 계산합니다.
   - **단점**: 시간 복잡도가 \( O(n^2) \)로 비효율적이며 입력 크기가 클 경우 성능이 떨어집니다.

2. **효율적인 접근 (단조 감소 스택 + 역방향 탐색)**  
   - **단조 감소 스택**을 사용하여 \( nums[i] \) 값을 기준으로 최소값의 인덱스를 저장합니다. 
   - 스택은 오름차순으로 정렬되며, 후속 탐색에서 최대 너비를 계산할 때 효율적으로 접근 가능합니다.
   - 시간 복잡도는 \( O(n) \)입니다.
*/
