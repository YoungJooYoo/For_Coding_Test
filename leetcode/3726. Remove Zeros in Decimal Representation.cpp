class Solution 
{
public:
    long long removeZeros(const long long n) const 
    {
        assert(MIN_N <= n && n <= MAX_N);

        const string num = to_string(n);
        string number;

        for (const char ch : num)
        {
            assert('0' <= ch && ch <= '9');
            if (ch != '0')
            {
                number.push_back(ch);
            }
        }

        return stoll(number);
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000000000000
    };
};

// https://leetcode.com/problems/remove-zeros-in-decimal-representation/
