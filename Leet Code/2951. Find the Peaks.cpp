class Solution {
public:
    vector<int> findPeaks(const vector<int>& mountain)
    {
        vector<int> result;
        const size_t LEN = mountain.size();

        for (size_t i = 1; i < LEN - 1; ++i) {
            if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
                result.push_back(i);
            }
        }

        return result;
    }
};


// https://leetcode.com/problems/find-the-peaks/description/
