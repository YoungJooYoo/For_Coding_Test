class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        vector<int> result(length, 0);
        
        for (const auto& update : updates) {
            int start = update[0];
            int end = update[1];
            int inc = update[2];
            
            result[start] += inc;
            
            if (end < length -1) {
                result[end + 1] -= inc;
            }
        }
        
        partial_sum(result.begin(), result.end(), result.begin());
        
        return result;
    }
};