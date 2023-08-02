class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector<int> odd;
        vector<int> even;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            }
            else {
                odd.push_back(nums[i]);
            }
        }

        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end());

        int j = 0;
        int k = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                nums[i] = even[j++];
            }
            else {
                nums[i] = odd[k++];
            }
        }
    
        return nums;
    }
};

// https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/
