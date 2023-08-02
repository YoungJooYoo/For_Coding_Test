class Solution {
private:
    string getRange(int lower, int upper) 
    {
        return (upper != lower) ? to_string(lower) + "->" + to_string(upper) : to_string(lower);
    }
    
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) 
    {
        vector<string> result;
        int prev = lower; // track the lower bound that has to be included in the range.
        
        for (size_t i = 0; i < nums.size(); ++i) {
            if (prev == INT_MAX) {
                return result;
            }
            else if (prev < nums[i]) {
                result.push_back(getRange(prev, nums[i] - 1)); // if nums[j] is INT_MIN then prev also will be INT_MIN. Thus the if condition will fail. Hence this subtraction is safe.
            }
            prev = (nums[i] == INT_MAX) ? INT_MAX : nums[i] + 1;
        }
        
        if ((prev != INT_MAX) && prev <= upper) {
            result.push_back(getRange(prev, upper));
        }
        
        return result;
    }
};