class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int nums_size = nums.size();
        int result =  nums[0] + nums[1] + nums[2];
        
        if (nums_size == 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums_size - 2; i++) {
                int j = i + 1;
                int k = nums_size - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - result)) {
                    if (sum == target) return sum;
                    result = sum;
                }
                if (target < sum) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        
        return result;
    }
};

/*
sum : 현재
result : 이전 값
*/