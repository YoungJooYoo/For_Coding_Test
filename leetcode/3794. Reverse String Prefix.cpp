class Solution 
{
public:
    string reversePrefix(string& s, const int k) const
    {
        
        string temp = s.substr(0, k);
        ranges::reverse(temp);

        for (int i = 0; i < k; ++i)
        {
            s[i] = temp[i];
            assert(islower(s[i]));
        }

        assert(temp.size() == k);
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        return s;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
    };
};

/ https://leetcode.com/problems/reverse-string-prefix/
