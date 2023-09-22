class Solution {
public:
    bool is_sorted(vector<int>& nums)
    {
        const size_t LEN = nums.size();

        for (size_t i = 0; i < LEN - 1; ++i) {
            if (nums[i] >= nums[i + 1]) return false;
        }

        return true;
    }

    int minimumRightShifts(vector<int>& nums) 
    {
        const int END = nums.size() - 1;
        int length = nums.size();
        int count = 0;

        while (length-- > 0 ) {
            if (is_sorted(nums) == true) return count;
            nums.insert(nums.begin(), nums[END]);
            nums.erase(nums.end() - 1);
            ++count;
        }

        return FAIL;
    }

private:
    enum { FAIL = -1 };
};

https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/description/
