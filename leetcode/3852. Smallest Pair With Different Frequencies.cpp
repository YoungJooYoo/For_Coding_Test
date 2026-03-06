class Solution {
public:
    vector<int> minDistinctFreqPair(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        map<int, int> freq;
        map<int, vector<int>> preResult;

        for (const int num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++freq[num];
        }

        for (const auto& [num, count] : freq) // 빈도 -> 값 목록
        {
            preResult[count].push_back(num);
        }

        for (auto& [count, numbers] : preResult) // 각 빈도 그룹 정렬
        {
            ranges::sort(numbers);
        }

        if (preResult.size() < 2)
        {
            return { INVALID, INVALID };
        }

        int x = INVALID;
        int xFreq = 0;

        // 가장 작은 x 찾기
        for (const auto& [num, count] : freq)
        {
            x = num;
            xFreq = count;
            break;
        }

        // x와 다른 빈도의 가장 작은 y 찾기
        for (const auto& [num, count] : freq)
        {
            if (count != xFreq)
            {
                return { x, num };
            }
        }

        return { INVALID, INVALID };
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 100,
        INVALID = -1
    };
};

// https://leetcode.com/problems/smallest-pair-with-different-frequencies/description/
