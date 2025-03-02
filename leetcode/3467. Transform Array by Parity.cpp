class Solution 
{
public:
    vector<int> transformArray(vector<int>& nums) 
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        for (auto& num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            if (num % 2 == 0)
            {
                num = 0;
            }
            else
            {
                num = 1;
            }
        }

        sort(nums.begin(), nums.end());

        return nums;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 1000,
    };
};

// https://leetcode.com/problems/transform-array-by-parity/description/

/*
다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**3467. 패리티에 따라 배열 변환하기**  
*Easy*  
*Topics*  
*Companies*  
*Hint*

정수 배열 **nums**가 주어집니다. 다음의 연산을 순서대로 수행하여 **nums**를 변환하세요:

1. 짝수는 모두 0으로 대체합니다.
2. 홀수는 모두 1로 대체합니다.
3. 변환된 배열을 오름차순(비내림차순)으로 정렬합니다.

이 연산들을 수행한 후의 결과 배열을 반환하세요.

---

**예제 1:**

- **입력:** nums = [4, 3, 2, 1]
- **출력:** [0, 0, 1, 1]
- **설명:**  
  짝수(4와 2)는 0, 홀수(3과 1)는 1로 대체합니다. 그러면 nums = [0, 1, 0, 1]이 되고, 이를 오름차순으로 정렬하면 [0, 0, 1, 1]이 됩니다.

---

**예제 2:**

- **입력:** nums = [1, 5, 1, 4, 2]
- **출력:** [0, 0, 1, 1, 1]
- **설명:**  
  짝수(4와 2)는 0, 홀수(1, 5, 1)는 1로 대체합니다. 그러면 nums = [1, 1, 1, 0, 0]이 되고, 이를 오름차순으로 정렬하면 [0, 0, 1, 1, 1]이 됩니다.

---

**제약 조건:**

- 1 <= nums.length <= 100  
- 1 <= nums[i] <= 1000

**추가 설명:**  
짝수의 개수를 x, 홀수의 개수를 y라고 할 때, 결과 배열은 0이 x번, 그 다음에 1이 y번 출력되어야 합니다.
*/
