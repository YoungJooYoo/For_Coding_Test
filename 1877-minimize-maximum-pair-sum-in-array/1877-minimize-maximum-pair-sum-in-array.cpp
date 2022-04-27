class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        int i = 0; // 시작 인덱스
        int j = nums.size() - 1; // 배열의 마지막 인덱스 
        int max_val = INT_MIN;        

        sort(nums.begin(), nums.end());
        
        while (i < j) {
            max_val = max(max_val, nums[i] + nums[j]);
            i++;
            j--;
        }
        
        return max_val;
    }
};