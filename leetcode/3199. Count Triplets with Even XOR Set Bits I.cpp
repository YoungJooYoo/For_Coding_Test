class Solution 
{
public:
    int tripletCount(const vector<int>& a, const vector<int>& b, const vector<int>& c) 
    {
        int count = 0;

        for (size_t i = 0; i < a.size(); ++i)
        {
            for (size_t j = 0; j < b.size(); ++j)
            {
                for (size_t k = 0; k < c.size(); ++k)
                {
                    const size_t num = a[i] ^ b[j] ^ c[k];
                    if (popcount(num) % 2 == 0) ++count;
                }
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/count-triplets-with-even-xor-set-bits-i/
