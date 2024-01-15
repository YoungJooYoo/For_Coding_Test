class Solution {
public:
    bool isFascinating(int n) 
    {
        const string fascinating = "123456789";
        string nums = to_string(n) + to_string(2 * n) + to_string(3 * n);

        sort(nums.begin(), nums.end());

        return nums == fascinating  ? true : false;
    }
};

// https://leetcode.com/problems/check-if-the-number-is-fascinating/description/
