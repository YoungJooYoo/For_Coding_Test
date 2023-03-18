class Solution {
public:
    int GCD(const int a, const int b)
    {
        if (b == 0) {
            return a;
        }
        else { 
            return GCD(b, a % b);
        }
    }

    int findGCD(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
    
        const int MIN_VAL = nums[0];
        const int MAX_VAL = nums[nums.size() -1];
        
        return GCD(MIN_VAL, MAX_VAL);
    }
};

// https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
