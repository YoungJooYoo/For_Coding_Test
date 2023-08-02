class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> result;

        for (const int& num : nums) {
            vector<int> remains;
            int temp = num;
            while (temp != 0) {
                remains.push_back(temp % 10);
                temp /= 10;
            }
            reverse(remains.begin(), remains.end());
            for (const int& remain : remains) {
                result.push_back(remain);
            }
        }

        return result;    
    }
};

https://leetcode.com/problems/separate-the-digits-in-an-array/description/
