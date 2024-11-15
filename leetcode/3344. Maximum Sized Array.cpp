class Solution 
{
public:
    int maxSizedArray(const long long s) 
    {
        return maxSizedArrayHelper(s);
    }

private:
    int maxSizedArrayHelper(const long long s) const
    {
        long long sumI = 0;
        long long sumJK = 0;

        for (int n = 1;; ++n)
        {   
            const long long prevIndex = n - 1;
            sumI += prevIndex;

            for (int j = 0; j < prevIndex; ++j) 
            {
                sumJK += (prevIndex | j) * 2;
            }

            sumJK += prevIndex;

            if (sumI * sumJK > s) 
            {
                return n - 1;
            }
        }
    }
};

// https://leetcode.com/problems/maximum-sized-array/description/
