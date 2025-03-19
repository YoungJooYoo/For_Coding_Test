class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int operations = 0;
        assert(n >= MIN_ARRAY_SIZE && n <= MAX_ARRAY_SIZE);
        
        for (int i = 2; i < n; ++i) // 인덱스 2부터 시작하여, 이전 3개 원소를 검사합니다.
        {
            assert(nums[i] == 0 || nums[i] == 1);
            if (nums[i - 2] == 0) // 만약 현재 위치에서 2칸 앞의 원소가 0이면, 해당 연산을 수행합니다.
            {
                nums[i - 2] = !nums[i - 2]; // 연속된 3개의 원소를 뒤집습니다.
                nums[i - 1] = !nums[i - 1];
                nums[i] = !nums[i];
                ++operations;
            }
        }
        
        for (const int num : nums) // 모든 원소가 1로 변경되었는지 확인합니다.
        {
            assert(num == 0 || num == 1);
            if (num == 0) 
            {
                return FAIL;
            }
        }
        
        return operations;
    }

private:
    enum
    {
        FAIL = -1,
        MIN_ARRAY_SIZE = 3,
        MAX_ARRAY_SIZE = 100000
    };
};

// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19

/*
**3191. 이진 배열의 모든 원소를 1로 만들기 위한 최소 연산 수 I**

**난이도:** 중간

**문제 설명:**  
이진 배열 **nums**가 주어집니다.

다음 연산을 배열에 대해 원하는 만큼(0번일 수도 있음) 수행할 수 있습니다:

- 배열에서 임의의 연속된 3개의 원소를 선택하여 모두 뒤집습니다.
  - 원소를 뒤집는다는 것은 0을 1로, 1을 0으로 변경하는 것을 의미합니다.

모든 **nums**의 원소를 1로 만들기 위해 필요한 최소 연산 수를 반환하세요.  
만약 모든 원소를 1로 만드는 것이 불가능하면 -1을 반환합니다.

---

**예제 1:**

- **입력:** nums = [0,1,1,1,0,0]  
- **출력:** 3  
- **설명:**  
  다음과 같은 연산을 수행할 수 있습니다:
  1. 인덱스 0, 1, 2의 원소를 선택하여 뒤집으면, 배열은 [1,0,0,1,0,0]이 됩니다.
  2. 인덱스 1, 2, 3의 원소를 선택하여 뒤집으면, 배열은 [1,1,1,0,0,0]이 됩니다.
  3. 인덱스 3, 4, 5의 원소를 선택하여 뒤집으면, 배열은 [1,1,1,1,1,1]이 됩니다.

---

**예제 2:**

- **입력:** nums = [0,1,1,1]  
- **출력:** -1  
- **설명:**  
  모든 원소를 1로 만들 수 없으므로, 결과는 -1입니다.

---

**제약 조건:**

- 3 <= nums.length <= 10^5  
- 0 <= nums[i] <= 1

---

**힌트:**

1. 만약 nums[0]이 0이라면, 이를 1로 바꾸는 유일한 방법은 배열의 처음 3개 원소에 연산을 수행하는 것입니다.
2. nums[0]을 1로 바꾼 후, 같은 논리를 나머지 배열에 적용해 보세요.

---
*/
