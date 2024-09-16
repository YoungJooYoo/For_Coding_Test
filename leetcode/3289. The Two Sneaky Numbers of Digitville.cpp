class Solution 
{
public:
    vector<int> getSneakyNumbers(const vector<int>& nums) 
    {
        vector<int> result;
        unordered_map<int , int> freq;

        for (const auto num : nums)
        {
            ++freq[num];
            if (freq[num] > 1 && find(result.begin(), result.end(), num) == result.end())
            {
                result.push_back(num);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/

/*
3289. Digitville의 두 장난꾸러기 숫자
**난이도:** 쉬움
**힌트**

**문제 설명:**

Digitville 마을에는 0부터 \(n - 1\)까지의 정수를 포함하는 `nums`라는 숫자 목록이 있었습니다. 각 숫자는 목록에 정확히 한 번씩 나타나야 했지만, 두 개의 장난꾸러기 숫자가 한 번 더 몰래 들어와서 목록이 평소보다 길어졌습니다.

마을의 탐정인 당신의 임무는 이 두 장난꾸러기 숫자를 찾아내는 것입니다. 이 두 숫자를 포함하는 크기가 2인 배열을 반환하여 Digitville에 평화를 되찾아주세요. 반환하는 배열의 순서는 상관없습니다.

---

**예제 1:**

```
입력: nums = [0,1,1,0]
출력: [0,1]
```

**설명:**

숫자 0과 1이 배열에 각각 두 번씩 나타납니다.

---

**예제 2:**

```
입력: nums = [0,3,2,1,3,2]
출력: [2,3]
```

**설명:**

숫자 2와 3이 배열에 각각 두 번씩 나타납니다.

---

**예제 3:**

```
입력: nums = [7,1,5,4,3,4,6,0,9,5,8,2]
출력: [4,5]
```

**설명:**

숫자 4와 5가 배열에 각각 두 번씩 나타납니다.

---

**제약 사항:**

- \(2 \leq n \leq 100\)
- `nums.length == n + 2`
- \(0 \leq nums[i] < n\)
- 입력은 `nums`에 정확히 두 개의 중복된 요소가 포함되도록 생성됩니다.

*/
