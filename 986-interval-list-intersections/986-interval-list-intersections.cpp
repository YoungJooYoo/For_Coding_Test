class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        vector<vector<int>> ans;
        size_t i = 0;
        size_t j = 0;
        
        for (size_t i = 0, j = 0; i < firstList.size() && j < secondList.size(); firstList[i][1] < secondList[j][1] ? ++i : ++j) 
        {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            
            if (start <= end) 
            {
                ans.push_back({start, end});
            }
            
        }
        
        return ans;
    }
};