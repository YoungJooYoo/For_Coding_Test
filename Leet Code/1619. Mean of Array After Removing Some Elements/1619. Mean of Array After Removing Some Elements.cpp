class Solution {
public:
    double trimMean(vector<int>& arr) 
    {
        int n = arr.size();
        int k = n / 20;

        sort(arr.begin(), arr.end());

        return accumulate(arr.begin() + k, arr.end() - k, 0) / double(n - 2 * k);
    }
};

// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/
