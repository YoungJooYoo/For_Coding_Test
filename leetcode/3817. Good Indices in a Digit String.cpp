class Solution
{
public:
    vector<int> goodIndices(const string& s) const
    {
        assert(MIN_LENGTH <= s.length() && s.length() <= MAX_LENGTH);
        
        const size_t LENGTH = s.length();
        vector<int> result;

        for (int index = 0; index < LENGTH; ++index)
        {
            assert('0' <= s[index] && s[index] <= '9');
            const string indexStr = to_string(index);
            const int digitCount = static_cast<int>(indexStr.length());
            const string sub = s.substr(index - digitCount + 1, digitCount);
            if (sub == indexStr)
            {
                assert(index >= 0);
                result.push_back(index);
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000
    };
};

// https://leetcode.com/problems/good-indices-in-a-digit-string/
