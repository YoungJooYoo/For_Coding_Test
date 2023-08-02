class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> freq;
        int result = INT_MIN;
        
        for (const auto& num : arr) {
            freq[num]++;
        }
        
        for (const auto& elem : freq) {
            if (elem.first == elem.second && result < elem.second) {
                result = elem.second;
            }
        }
        
        return result == INT_MIN ? -1 : result;
    }
};