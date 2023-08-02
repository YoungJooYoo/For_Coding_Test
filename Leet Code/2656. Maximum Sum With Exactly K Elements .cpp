class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        const size_t LAST_INDEX = nums.size() - 1;
        int sum = 0;

        while (k-- != 0 ) {
            sum += nums[LAST_INDEX]++; // sum = sum + nums[LAST_INDEX]  ->   ++nums[LAST_INDEX];
        }

        return sum;
    }
};


// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/
