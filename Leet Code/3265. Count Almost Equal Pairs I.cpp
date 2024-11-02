class Solution 
{
public:
    int countPairs(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int count = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {   
            const int currNum = nums[i];
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                const int nextNum = nums[j];
                if (currNum == nextNum || isAlmostEqual(currNum, nextNum) == true || isAlmostEqual(nextNum, currNum) == true)
                {
                    ++count;
                }
            }
        }

        return count;
    }

private:
    bool isAlmostEqual(const int num0, const int num1)
    {
        string strA = to_string(num0);
        const string strB = to_string(num1);
        const size_t LENGTH = strA.size();

        for (size_t i = 0; i < LENGTH; ++i)
        {
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                swap(strA[i], strA[j]); // 두 자리를 교환하여 같아질 수 있는지 확인
                if (stoi(strA) == stoi(strB)) return true;
                swap(strA[i], strA[j]); // 교환 원상복구
            }
        }

        return false;
    }
};

// https://leetcode.com/problems/count-almost-equal-pairs-i/

/*
**3265. 거의 동일한 쌍의 개수 I**  
난이도: 중간

주제: 배열, 브루트 포스, 수학

---

양의 정수로 구성된 배열 `nums`가 주어집니다.

이 문제에서 두 정수 `x`와 `y`는 다음 연산을 **최대 한 번** 수행한 후 동일해질 수 있으면 **거의 동일**하다고 합니다:

- `x` 또는 `y` 중 하나를 선택하고, 선택한 숫자 안에서 두 자리를 교환합니다.

배열 `nums`에서 `i < j`를 만족하는 인덱스 `i`와 `j` 쌍의 개수를 반환하세요. 이때 `nums[i]`와 `nums[j]`는 거의 동일해야 합니다.

참고로, 연산을 수행한 후에는 정수에 **선행 0이 포함**될 수 있습니다.

---

### 예제 1:

입력: 
```
nums = [3,12,30,17,21]
```
출력: 
```
2
```
설명: 
거의 동일한 쌍의 요소들은 다음과 같습니다:
- `3`과 `30`: `30`에서 `3`과 `0`을 교환하면 `3`이 됩니다.
- `12`와 `21`: `12`에서 `1`과 `2`를 교환하면 `21`이 됩니다.

### 예제 2:

입력: 
```
nums = [1,1,1,1,1]
```
출력: 
```
10
```
설명: 
배열의 모든 두 요소는 거의 동일합니다.

### 예제 3:

입력: 
```
nums = [123,231]
```
출력: 
```
0
```
설명: 
`123`이나 `231`의 어떤 두 자리도 교환하여 다른 숫자를 만들 수 없습니다.

---

### 제약 사항:

- `2 <= nums.length <= 100`
- `1 <= nums[i] <= 10^6` 

--- 

이 문제에서는 숫자 안의 두 자리를 교환하여 두 숫자가 동일해질 수 있는지 확인하여 쌍의 개수를 계산하는 것입니다. 교환 후 선행 0이 포함되어도 허용됩니다.
*/
