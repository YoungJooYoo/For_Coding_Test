class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        while (nums.size() > 1) {
            vector<int> temp;
            int count = 0;
            for (size_t i = 0; i < nums.size() - 1; i += 2) {
                if (count %  2 == 0) {
                    temp.push_back(min(nums[i], nums[i + 1]));
                    ++count;
                }
                else {
                    temp.push_back(max(nums[i], nums[i + 1]));
                    ++count;
                }
            }
            nums = temp;
        }

        return nums[0];    
    }
};

// https://leetcode.com/problems/min-max-game/description/
