class Solution {
public:
    string triangleType(vector<int>& nums) 
    {
       sort(nums.begin(), nums.end()); // 변의 길이를 정렬
       
       if (nums[0] + nums[1] <= nums[2]) {
           return "none"; // 삼각형의 조건을 만족하지 않음
       }
       else if (nums[0] == nums[1] && nums[1] == nums[2]) {
           return "equilateral";
       }
       else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
           return "isosceles";
       }
       else {
           return "scalene"; 
       }
    }
};

// https://leetcode.com/problems/type-of-triangle/description/
