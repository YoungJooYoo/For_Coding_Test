class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>> res;
        int  start = toBeRemoved[0];
        int end = toBeRemoved[1];
        
        for (const auto& v : intervals) {
            if (v[1] <= start || v[0] >= end) res.push_back(v);
            else {
                if (v[0] < start) res.push_back({v[0], start});
                if (v[1] > end) res.push_back({end, v[1]});
            }
        }
        
        return res;
    }
};