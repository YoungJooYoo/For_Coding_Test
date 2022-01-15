class Solution {
public:
     int longestWPI(vector<int>& hours) 
     {
        const size_t hours_length = hours.size();
        unordered_map<int, int> seen;
        int res = 0; 
        int score = 0; 
        
        for (int i = 0; i < hours_length; ++i) {
            hours[i] = hours[i] > 8 ? 1 : -1;
            score = score + hours[i];
            if (score > 0) {
                res = i + 1;
            } 
            else {
                if (seen.find(score) == seen.end()) {
                   seen[score] = i;
                }
                if (seen.find(score - 1) != seen.end()) {
                    res = max(res, i - seen[score - 1]);
                } 
            }
        }
         
        return res;
    }
};