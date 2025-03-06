class Solution 
{
public:
    int maxCount(const vector<int>& banned, const int n, const int maxSum) const
    {
        unordered_set<int> bannedSet;
        int selectedCount = 0;
        int currentSum = 0;

        for (const auto num : banned)
        {
            assert(MIN_BANNED <= num && num <= MAX_BANNED);
            bannedSet.insert(num);
        }
        
        for (int i = 1; i <= n; ++i)
        {
            if (bannedSet.find(i) == bannedSet.end())
            {
                if (currentSum + i <= maxSum)
                {
                    currentSum += i;
                    ++selectedCount;
                }
                else
                {
                    return selectedCount;
                }
            }
        }

        assert(MIN_BANNED_LENGTH <= banned.size() && banned.size() <= MAX_BANNED_LENGTH);
        assert(MIN_SUM <= maxSum && maxSum <= MAX_SUM);
        assert(currentSum <= maxSum);

        return selectedCount;
    }

private:
    enum  
    {
        MIN_BANNED_LENGTH = 1,
        MAX_BANNED_LENGTH = 10000,
        MIN_BANNED = 1,
        MAX_BANNED = 10000,
        MIN_SUM = 1,
        MAX_SUM = 1000000000,
    };
};

// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-05

/*



**2554. 범위에서 선택할 수 있는 정수의 최대 개수 I**

**난이도:** Medium

**문제 설명:**

정수 배열 **banned**와 두 개의 정수 **n** 및 **maxSum**이 주어집니다. 아래의 규칙을 따르면서 정수들을 선택하려고 합니다.

- 선택된 정수는 모두 [1, n] 범위 내에 있어야 합니다.
- 각 정수는 최대 한 번만 선택할 수 있습니다.
- 선택된 정수는 **banned** 배열에 포함되어 있으면 안 됩니다.
- 선택된 정수들의 합은 **maxSum**을 초과해서는 안 됩니다.

위의 조건을 모두 만족하면서 선택할 수 있는 정수의 최대 개수를 반환하세요.

---

**예제 1:**

- **입력:** banned = [1,6,5], n = 5, maxSum = 6  
- **출력:** 2  
- **설명:**  
  정수 2와 4를 선택할 수 있습니다.  
  2와 4는 [1, 5] 범위 내에 있으며, banned 배열에 등장하지 않고, 이들의 합은 6으로 maxSum을 초과하지 않습니다.

---

**예제 2:**

- **입력:** banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1  
- **출력:** 0  
- **설명:**  
  주어진 조건을 만족하면서 선택할 수 있는 정수가 없습니다.

---

**예제 3:**

- **입력:** banned = [11], n = 7, maxSum = 50  
- **출력:** 7  
- **설명:**  
  정수 1, 2, 3, 4, 5, 6, 7을 모두 선택할 수 있습니다.  
  이들 모두 [1, 7] 범위에 속하며, banned 배열에 포함되어 있지 않고, 합계는 28로 maxSum을 초과하지 않습니다.

---

**제약 조건:**

- 1 <= banned.length <= 10⁴  
- 1 <= banned[i], n <= 10⁴  
- 1 <= maxSum <= 10⁹

---

**힌트:**

1. n 이하의 banned 숫자들을 집합에 저장합니다.
2. 1부터 n까지 순회하면서, banned에 포함되지 않은 숫자라면 선택합니다.
3. banned에 포함되지 않은 숫자들을 선택하면서, 그 합이 maxSum 이하가 되는지 확인합니다.
*/
