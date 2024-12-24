class Solution 
{
public:
    int countSubarrays(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int subArrayCount = 0;

        for (size_t i = 0, j = i + 2; j < LENGTH; ++i, ++j)
        {
            const int sum = (nums[i] + nums[j]) * 2;
            if (sum == nums[i + 1]) ++subArrayCount;
        }

        return subArrayCount;
    }
};

// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/

/*
**3392. 길이가 3인 조건을 만족하는 하위 배열 개수 세기**  
난이도: 쉬움

---

### 문제 설명  
정수 배열 `nums`가 주어졌을 때, 길이가 3인 하위 배열(subarray) 중 다음 조건을 만족하는 하위 배열의 개수를 반환하세요:  
- 첫 번째 숫자와 세 번째 숫자의 합이 두 번째 숫자의 절반과 정확히 같아야 합니다.

하위 배열은 배열 내의 연속적인 요소로 이루어진 비어 있지 않은 부분 배열입니다.

---

### 예제  

**예제 1:**  
입력: `nums = [1,2,1,4,1]`  
출력: `1`  
**설명:**  
길이가 3인 하위 배열 `[1,4,1]`에서 첫 번째 숫자와 세 번째 숫자의 합이 `1 + 1 = 2`로, 두 번째 숫자의 절반인 `4 / 2 = 2`와 같습니다.  

**예제 2:**  
입력: `nums = [1,1,1]`  
출력: `0`  
**설명:**  
하위 배열 `[1,1,1]`은 길이가 3인 유일한 하위 배열입니다. 하지만 첫 번째 숫자와 세 번째 숫자의 합이 두 번째 숫자의 절반과 같지 않습니다.

---

### 제약 조건  

- `3 <= nums.length <= 100`  
- `-100 <= nums[i] <= 100`
*/
