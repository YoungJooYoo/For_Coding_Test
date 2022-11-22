class Solution {
public:
    int sumOfDigits(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int temp = nums[0];
        int sum = 0;
        
        while(temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        
        return (sum % 2 != 0) ? 0 : 1;
    }
};