class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        const size_t ARRAY_SIZE = timePoints.size();
        vector<int>time;
        
        for (size_t i = 0; i < ARRAY_SIZE; i++) {
            time.push_back(stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2)));
        }
           
        sort(time.begin(), time.end());
        int ans = INT_MAX;
        
        for (size_t i = 1; i < ARRAY_SIZE; i++) {
            ans = min(time[i] - time[i - 1], ans);
        }
        
        ans = min(ans, time[0] - time[ARRAY_SIZE - 1] + 24 * 60);
        
        return ans;
        
    }
};