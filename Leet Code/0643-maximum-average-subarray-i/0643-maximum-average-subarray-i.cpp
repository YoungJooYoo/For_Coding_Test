class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double sum = 0;
        double result = INT_MIN; 
        
        for (size_t i = 0; i < k; i++) {
            sum += nums[i];    
        }
        result = max(result, sum / k);
        
        for (size_t i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            result = max(result, sum / k);
        }
        
        return result;
    }
};
