class Solution 
{
public:
    long long countGood(const vector<int>& nums, const int k) const 
    {
        assert(nums.size() >= MIN_SIZE && nums.size() <= MAX_SIZE);

        unordered_map<int, int> freq;
        const int n = nums.size();
        long long answer = 0;
        long long pairs = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) 
        {
            assert(nums[right] >= MIN_NUM && nums[right] <= MAX_NUM);
            const int val = nums[right];
            pairs += freq[val];
            ++freq[val];
            
            while (pairs >= k && left <= right) 
            {
                answer += (n - right);
                const int leftVal = nums[left];
                --freq[leftVal];
                pairs -= freq[leftVal];
                ++left;
            }
        }
        
        return answer;
    }
    
private:
    enum 
    {
        MIN_SIZE = 1,
        MAX_SIZE = 100000,
        MIN_NUM = 1,
        MAX_NUM = 1000000000
    };
};

// https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16

/*


**2537. 좋은 부분 배열의 개수 구하기**

**난이도:** 중간

**문제 설명:**  
정수 배열 **nums**와 정수 **k**가 주어집니다.  
**nums**의 "좋은 부분 배열(good subarray)"의 개수를 반환하세요.

여기서, 부분 배열 **arr**은 다음 조건을 만족할 때 "좋다"라고 합니다:  
- **arr** 내에서, i < j이고 **arr[i] == arr[j]**인 인덱스 쌍 (i, j)가 **최소 k개** 존재해야 합니다.

부분 배열은 배열 내에서 연속된(contiguous) 비어있지 않은 원소들의 나열을 의미합니다.

---

**예제 1:**

- **입력:** nums = [1,1,1,1,1], k = 10  
- **출력:** 1  
- **설명:**  
  좋은 부분 배열은 nums 전체 배열 하나뿐입니다.

---

**예제 2:**

- **입력:** nums = [3,1,4,3,2,2,4], k = 2  
- **출력:** 4  
- **설명:**  
  다음과 같이 4개의 서로 다른 좋은 부분 배열이 있습니다:
  - [3,1,4,3,2,2] (2쌍 존재)
  - [3,1,4,3,2,2,4] (3쌍 존재)
  - [1,4,3,2,2,4] (2쌍 존재)
  - [4,3,2,2,4] (2쌍 존재)

---

**제약 조건:**

- 1 <= nums.length <= 10^5  
- 1 <= nums[i], k <= 10^9

---
*/
