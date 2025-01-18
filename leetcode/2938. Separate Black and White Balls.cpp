class Solution 
{
public:
    long long minimumSteps(string& s) 
    {
        assert(MIN_SIZE <= s.size() && s.size() <= MAX_SIZE);
        
        long long result = 0;
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            assert(s[left] == '0' or s[left] == '1');
            assert(s[right] == '0' or s[right] == '1');
            if (s[left] == '1' && s[right] == '0')
            {
                swap(s[left], s[right]);
                assert(right - left >= 0);
                result += right - left;
                ++left;
                --right;
            }
            else if (s[left] == '0')
            {
                ++left;
            }
            else if (s[right] == '1')
            {
                --right;
            }
            else
            {
                assert(false);
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_SIZE = 1,
        MAX_SIZE = 100000
    };
};

// https://leetcode.com/problems/separate-black-and-white-balls/description/
