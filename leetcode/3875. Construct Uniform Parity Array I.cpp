class Solution 
{
public:
    bool uniformArray(const vector<int>& nums1) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums1.size()) && static_cast<int>(nums1.size()) <= MAX_LENGTH);
        return true;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 1,
        MAX_VALUE  = 100,
    };
};

// https://leetcode.com/problems/construct-uniform-parity-array-i/description/
