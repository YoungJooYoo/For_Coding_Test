class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string, int> freq;

        for (const auto& elem : arr) {
            freq[elem]++;
        }
     
        for (const auto& str : arr) {
            if (freq[str] == 1) {
                --k;
                if (k == 0) {
                    return str;
                }
            }
        }
 
        return "";    
    }
};

// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/
