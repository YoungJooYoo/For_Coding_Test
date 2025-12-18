class Solution
{
public:
    vector<int> distinctNumbers(const vector<int>& nums, const int k) const
    {
        assert(k >= MIN_K && k <= nums.size());

        const size_t LENGTH = nums.size();
        unordered_map<int, int> freq;
        vector<int> result;
        
        for (int i = 0; i < k; ++i)
        {
            ++freq[nums[i]];
        }
        result.push_back(static_cast<int>(freq.size()));

        for (size_t right = k; right < LENGTH; ++right)
        {
            const int leftValue = nums[right - k];
            const int rightValue = nums[right];
            if (--freq[leftValue] == 0) // 왼쪽 제거
            {
                freq.erase(leftValue);
            }
            ++freq[rightValue];
            result.push_back(static_cast<int>(freq.size()));
        }

        return result;
    }

private:
    enum
    {
        MIN_K = 1
    };
};
// https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/?source=submission-noac

/*
**1852. 각 부분 배열의 서로 다른(중복 없는) 숫자 개수 구하기**

**난이도:** 중간

**문제 설명:**  
길이 \(n\)인 정수 배열 **nums**와 정수 **k**가 주어집니다.  
배열 **nums**에서 크기 \(k\)인 모든 연속 부분 배열(서브배열)에 대해, 그 부분 배열 안에 포함된 **서로 다른** 원소의 개수를 구하려 합니다.

\[
\text{ans}[i] = \bigl|\{\,\text{nums}[j]\mid i \le j \le i+k-1\}\bigr|
\]
를 만족하는 정수 배열 **ans**를 반환하세요. 여기서 \(0 \le i \le n-k\)입니다.

---

**예제 1:**

- **입력:** nums = [1,2,3,2,2,1,3], k = 3  
- **출력:** [3,2,2,2,3]  
- **설명:**  
  - nums[0..2] = [1,2,3] → 서로 다른 값 3개  
  - nums[1..3] = [2,3,2] → 서로 다른 값 2개  
  - nums[2..4] = [3,2,2] → 서로 다른 값 2개  
  - nums[3..5] = [2,2,1] → 서로 다른 값 2개  
  - nums[4..6] = [2,1,3] → 서로 다른 값 3개  

---

**예제 2:**

- **입력:** nums = [1,1,1,1,2,3,4], k = 4  
- **출력:** [1,2,3,4]  
- **설명:**  
  - nums[0..3] = [1,1,1,1] → 1개  
  - nums[1..4] = [1,1,1,2] → 2개  
  - nums[2..5] = [1,1,2,3] → 3개  
  - nums[3..6] = [1,2,3,4] → 4개  

---

**제약 조건:**

- \(1 \le k \le \text{nums.length} \le 10^5\)  
- \(1 \le \text{nums}[i] \le 10^5\)  
*/
