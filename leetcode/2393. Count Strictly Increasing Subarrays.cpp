class Solution 
{
public:
    long long countSubarrays(const vector<int>& nums) 
    {
        if (nums.empty()) 
        {
            return 0;
        }

        long long count = 1; // 첫 번째 요소는 항상 단일 요소 부분 배열
        long long current = 1;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] < nums[i])
            {
                ++current;
            }
            else
            {
                current = 1;
            }
            count += current;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-strictly-increasing-subarrays/description/
