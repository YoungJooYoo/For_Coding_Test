class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());

        const size_t LEN = arr.size();
        const int temp = arr[1] - arr[0];

        for (size_t i = 0; i < LEN - 1; ++i) {
            if (arr[i + 1] - arr[i] != temp) return false;
        }   


        return true; 
    }
};

// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
