class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        set<int> num1(nums1.begin(), nums1.end());
        set<int> num2(nums2.begin(), nums2.end());
        
        for (const auto& elem : num1) {
            if (num2.find(elem) == num2.end()) temp.push_back(elem);
        }
        result.push_back(temp);
        temp.clear();

        for (const auto& elem : num2) {
            if (num1.find(elem) == num1.end()) temp.push_back(elem);
        }
        result.push_back(temp);

        return result;
    }
};

https://leetcode.com/problems/find-the-difference-of-two-arrays/description/
