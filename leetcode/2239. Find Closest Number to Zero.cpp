class Solution {
public:
    int findClosestNumber(vector<int>& nums) 
    {
        sort(begin(nums), end(nums));
        
        int min_distance = INT_MAX;

        for (const auto& num : nums) {
            if (abs(num) <= abs(min_distance)) {
                min_distance = num;
            }
        }

        return min_distance;    
    }
};

https://leetcode.com/problems/find-closest-number-to-zero/description/
