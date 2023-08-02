class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int temp = 0;

        for (size_t i = 1; i < pref.size(); ++i) {
            temp ^= pref[i - 1];
            pref[i] = temp ^ pref[i];
        }

        return pref;
    }
};

// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/
