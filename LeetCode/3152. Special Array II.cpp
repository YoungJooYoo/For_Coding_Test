class Solution 
{
public:
    vector<bool> isArraySpecial(const vector<int>& nums, const vector<vector<int>>& queries) const
    {
        const size_t n = nums.size();
        const size_t q = queries.size();
        vector<int> bad(n, 0);
        vector<int> prefixBad(n + 1, 0);
        vector<bool> answer;

        assert(q >= MIN_QUERIES_LENGTH && q <= MAX_QUERIES_LENGTH);
        assert(n >= MIN_NUMS_LENGTH && n <= MAX_NUMS_LENGTH);

        for (size_t i = 0; i + 1 < n; ++i) 
        {
            assert(nums[i] >= MIN_NUM_VALUE && nums[i] <= MAX_NUM_VALUE);
            bad[i] = (nums[i] % 2 == nums[i + 1] % 2) ? 1 : 0;
            assert(bad[i] == true or bad[i] == false);
        }

        for (size_t i = 0; i < n; ++i) 
        {
            prefixBad[i + 1] = prefixBad[i] + bad[i];
        }

        for (const auto& query : queries) 
        {
            assert(query.size() == 2);
            const int from = query[0];
            const int to   = query[1];
            assert(from >= 0 && from < static_cast<int>(n));
            assert(to >= from && to < static_cast<int>(n));
            const bool hasEqualParityPair = (prefixBad[to] - prefixBad[from]) > 0;
            answer.push_back(!hasEqualParityPair);
        }

        return answer;
    }

private:
    enum
    {
        MIN_NUMS_LENGTH    = 1,
        MAX_NUMS_LENGTH    = 100000,
        MIN_NUM_VALUE      = 1,
        MAX_NUM_VALUE      = 100000,
        MIN_QUERIES_LENGTH = 1,
        MAX_QUERIES_LENGTH = 100000
    };
};
// https://leetcode.com/problems/special-array-ii/description/
