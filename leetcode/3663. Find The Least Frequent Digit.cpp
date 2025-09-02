class Solution
{
public:
    int getLeastFrequentDigit(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        const string strNumber = to_string(n);
        map<int, int, greater<int>> freqMap;
        int minFreq = MAX_N;
        int leastDigit = MAX_N;

        for (const char ch : strNumber)
        {
            const int digit = ch - '0';
            ++freqMap[digit];
        }

        for (const auto& [digit, count] : freqMap)
        {
            minFreq = min(minFreq, count);
            if (count == minFreq)
            {
                leastDigit = digit;
            }
        }

        return leastDigit;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = numeric_limits<int>::max()
    };
};

// https://leetcode.com/problems/find-the-least-frequent-digit/description/
