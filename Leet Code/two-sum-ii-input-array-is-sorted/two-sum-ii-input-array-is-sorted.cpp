class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const size_t num_length = numbers.size();
        vector<int> result;
        int start = 0;
        int end = num_length - 1;
        
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            } 
            else if (numbers[start] + numbers[end] > target) {
                end--;
            }
            else {
                start++;
            }
        }
        
        return result;
    }
};