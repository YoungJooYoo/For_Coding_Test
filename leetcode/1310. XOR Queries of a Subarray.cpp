class Solution
{
public:
    vector<int> xorQueries(const vector<int>& arr, const vector<vector<int>>& queries) const
    {
        assert(MIN_LENGTH <= arr.size() && arr.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= queries.size() && queries.size() <= MAX_LENGTH);

        const size_t LENGTH = arr.size();
        vector<int> prefixXor(LENGTH);
        vector<int> result;
        result.reserve(queries.size());
        prefixXor[0] = arr[0];
        assert(MIN_VALUE <= arr[0] && arr[0] <= MAX_VALUE);
        
        for (size_t i = 1; i < LENGTH; ++i)
        {
            assert(MIN_VALUE <= arr[i] && arr[i] <= MAX_VALUE);
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }

        for (const auto& query : queries)
        {
            const int left = query[LEFT_INDEX];
            const int right = query[RIGHT_INDEX];
            const int xorSum = (left == 0) ? prefixXor[right] : (prefixXor[right] ^ prefixXor[left - 1]);
            result.push_back(xorSum);
            assert(query.size() == QUERY_LENGTH);
            assert(0 <= left);
            assert(left <= right);
            assert(static_cast<size_t>(right) < LENGTH);
        }

        assert(result.size() == queries.size());
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 30000,
        MIN_VALUE = 1,
        MAX_VALUE = 1000000000,
        QUERY_LENGTH = 2,
        LEFT_INDEX = 0,
        RIGHT_INDEX = 1
    };
};
// https://leetcode.com/problems/xor-queries-of-a-subarray/
