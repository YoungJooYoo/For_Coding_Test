class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        size_t odd_count = 0;

        for (const auto& num : arr) {
            if (num % 2 == 1) {
                ++odd_count;
                if (odd_count == 3) {
                    return true;
                }
            }
            else {
                odd_count = 0;
            }
        }

        return false;    
    }
};

// https://leetcode.com/problems/three-consecutive-odds/description/
