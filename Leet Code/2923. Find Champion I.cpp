class Solution {
public:
    int findChampion(const vector<vector<int>>& grid) 
    {
        int max_val = INT_MIN;
        int index = 0;
        map<int, int> sums; // sum - index로 키 밸류 묶음

        for (const auto& array : grid) {
            sums[accumulate(array.begin(), array.end(), 0)] = index;
            ++index;
        }

        // 마지막값이 최대값 한칸 뒤로 가야 원소의 마지막 값.
        auto result = sums.end();
        --result;
        result->second;
        return result->second;;    
    }
};

// https://leetcode.com/problems/find-champion-i/description/
