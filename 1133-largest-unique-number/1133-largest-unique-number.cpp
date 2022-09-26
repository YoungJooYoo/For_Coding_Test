class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        int max = -1;
        
        for (const auto& num : nums) {
            freq[num]++;
        }
        
        for (const auto& elem : freq) {
            if (elem.second == 1 && elem.first > max) {
                max = elem.first;
            }
        }
        
        return max;
    }
};