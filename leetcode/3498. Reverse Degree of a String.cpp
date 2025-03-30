class Solution 
{
public:
int reverseDegree(const string &s) const
{
    assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

    int degree = 0;

    for (size_t i = 0; i < s.size(); ++i) 
    {
        const size_t idx = s[i] - 'a';
        degree += mKReversedAlphabet[idx] * (i + 1);
    }

    assert(degree > 0);
    return degree;
}


private:
    const vector<int> mKReversedAlphabet = 
    {
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 
        14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 1000
    };
};

// https://leetcode.com/problems/reverse-degree-of-a-string/description/
