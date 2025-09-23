class Solution
{
public:
    int smallestAbsent(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const unordered_set<int> present(nums.begin(), nums.end());
        const double average = accumulate(nums.begin(), nums.end(), 0) / static_cast<double>(nums.size());
        int candidate = ((static_cast<int>(floor(average)) + 1) <= 0) ? 1 : (static_cast<int>(floor(average)) + 1); // 평균을 넘는 가장 작은 정수의 최소 시작점

        while (present.count(candidate) == true)
        {
            ++candidate;
        }

        return candidate;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VAL = -100,
        MAX_VAL = 100,
    };
};

// https://leetcode.com/problems/smallest-absent-positive-greater-than-average/description/
