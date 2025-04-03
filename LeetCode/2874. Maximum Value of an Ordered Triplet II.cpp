class Solution 
{
public:
    long long maximumTripletValue(const vector<int>& nums) const 
    {
        const int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        long long maxTripletValue = 0; // 모든 후보가 음수일 경우 0을 반환합니다.

        assert(n >= MIN_N);

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) 
        {
            assert(nums[i] >= MIN_VALUE && nums[i] <= MAX_VALUE);
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        
        suffixMax[n - 1] = nums[n - 1];  // suffix_max[i] : nums[i]부터 nums[n-1]까지의 최대값
        for (int i = n - 2; i >= 0; --i) 
        {
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }
        
        for (int j = 1; j <= n - 2; ++j)  
        {
            const long long candidate = (static_cast<long long>(prefixMax[j - 1]) - nums[j]) * suffixMax[j + 1];
            maxTripletValue = max(maxTripletValue, candidate);
        }
        
        return maxTripletValue;
    }
    
private:
    enum {
        MIN_N = 3,             // 배열 길이는 최소 3이어야 함
        MIN_VALUE = 1,         // 각 원소의 최소값
        MAX_VALUE = 1000000    // 각 원소의 최대값 (문제에 따라 1e6)
    };
};

// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/?envType=daily-question&envId=2025-04-03

/*
다음은 문제의 국문 번역입니다.

---

**2874. 순서 있는 삼중 쌍의 최대값 II**

**난이도:** 중간

**문제 설명:**  
0-indexed 정수 배열 **nums**가 주어집니다.

조건을 만족하는 모든 인덱스 삼중 쌍 (i, j, k) (단, i < j < k)에 대해, 해당 삼중 쌍의 값을 계산합니다.  
삼중 쌍 (i, j, k)의 값은 **(nums[i] - nums[j]) * nums[k]**로 정의됩니다.

모든 가능한 삼중 쌍 중에서 최대 값을 반환하세요.  
만약 모든 삼중 쌍의 값이 음수라면, 0을 반환합니다.

---

**예제 1:**

- **입력:** nums = [12, 6, 1, 2, 7]  
- **출력:** 77  
- **설명:**  
  삼중 쌍 (0, 2, 4)의 값은 (nums[0] - nums[2]) * nums[4] = (12 - 1) * 7 = 77이며, 77보다 큰 값은 존재하지 않습니다.

---

**예제 2:**

- **입력:** nums = [1, 10, 3, 4, 19]  
- **출력:** 133  
- **설명:**  
  삼중 쌍 (1, 2, 4)의 값은 (nums[1] - nums[2]) * nums[4] = (10 - 3) * 19 = 133이며, 133보다 큰 값은 존재하지 않습니다.

---

**예제 3:**

- **입력:** nums = [1, 2, 3]  
- **출력:** 0  
- **설명:**  
  유일한 삼중 쌍 (0, 1, 2)의 값은 (nums[0] - nums[1]) * nums[2] = (1 - 2) * 3 = -3입니다.  
  모든 삼중 쌍의 값이 음수이므로 0을 반환합니다.

---

**제약 조건:**

- 3 <= nums.length <= 10^5  
- 1 <= nums[i] <= 10^6

---

이 문제의 해결을 위해 힌트로, prefix 최대 배열과 suffix 최대 배열을 이용해 각 인덱스 j에 대해  
**(prefix_max[j - 1] - nums[j]) * suffix_max[j + 1]** 의 값을 계산하는 방법을 사용할 수 있습니다.

*/
