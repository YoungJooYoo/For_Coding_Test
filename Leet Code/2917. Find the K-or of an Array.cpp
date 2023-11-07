class Solution {
public:
    int findKOr(const vector<int>& nums, const int k) 
    {
        int result = 0;

        for (int bit = 0; bit < INT_LENGTH; ++bit) {
            int count = 0;
            for (const int num : nums) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }
            if (count >= k) {
                result |= (1 << bit);
            }
        }

        return result;
    }

private:
    enum { INT_LENGTH = 32 };
};

// https://leetcode.com/problems/find-the-k-or-of-an-array/description/
