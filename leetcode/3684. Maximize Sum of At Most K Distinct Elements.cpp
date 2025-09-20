class Solution 
{
public:
    vector<int> maxKDistinct(const vector<int>& nums, const int k) const
    {
        assert(MIN_LENGTH <= k && k <= MAX_LENGTH);
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        set<int, greater<int>> st;
        for (const auto num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            st.insert(num);
        }

        vector<int> result;
        auto it = st.begin();
        while (result.size() < k && it != st.end())
        {
            result.push_back(*it++);
        }

        assert(result.size() >= 1);
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 1000000000,
    };
};

// https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/description/

/*
### 3684. 최대 K개의 고유한 원소 합 최대화

양의 정수 배열 `nums`와 정수 `k`가 주어집니다.

`nums`에서 최대 `k`개의 원소를 선택하여 그 합을 최대로 만드세요. 단, 선택된 숫자들은 **고유해야 합니다(서로 달라야 합니다)**.

선택된 숫자들을 내림차순으로 정렬하여 배열로 반환하세요.

**예시 1:**

**입력:** `nums = [84,93,100,77,90], k = 3`
**출력:** `[100,93,90]`
**설명:**
최대 합은 283이며, 이는 93, 100, 90을 선택했을 때 얻을 수 있습니다. 이 숫자들을 내림차순으로 정렬하면 `[100, 93, 90]`이 됩니다.

**예시 2:**

**입력:** `nums = [84,93,100,77,93], k = 3`
**출력:** `[100,93,84]`
**설명:**
최대 합은 277이며, 이는 84, 93, 100을 선택했을 때 얻을 수 있습니다. 이 숫자들을 내림차순으로 정렬하면 `[100, 93, 84]`가 됩니다. 선택된 숫자는 고유해야 하므로 93, 100, 93을 선택할 수는 없습니다.
*/
