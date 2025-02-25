class Solution 
{
public:
    int numOfSubarrays(const vector<int>& arr) const
    {
        assert(arr.size() >= MIN_ARR_SIZE && arr.size() <= MAX_ARR_SIZE);
        
        const long long MOD = 1000000007LL;
        long long evenCount = 1;  // 초기 prefix sum 0은 짝수
        long long oddCount = 0;
        long long prefixParity = 0;  // 현재까지의 prefix sum의 패리티 (0: 짝수, 1: 홀수)
        long long result = 0;
        
        for (const int& num : arr)
        {
            assert(num >= MIN_NUM_VALUE && num <= MAX_NUM_VALUE);
            prefixParity = (prefixParity + num) % 2;
            if (prefixParity == 0)
            {
                result = (result + oddCount) % MOD; // 현재 prefix sum이 짝수라면, 이전 홀수 prefix sum과의 차이는 홀수가 됨.
                ++evenCount;
            }
            else
            {
                result = (result + evenCount) % MOD; // 현재 prefix sum이 홀수라면, 이전 짝수 prefix sum과의 차이는 홀수가 됨.
                ++oddCount;
            }
        }
        
        return static_cast<int>(result);
    }

private:
    enum
    {
        MIN_ARR_SIZE = 1,
        MAX_ARR_SIZE = 100000,
        MIN_NUM_VALUE = 1,
        MAX_NUM_VALUE = 1000
    };
};

// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
