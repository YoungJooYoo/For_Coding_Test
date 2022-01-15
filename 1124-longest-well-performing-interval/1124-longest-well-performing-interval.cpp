class Solution {
public:
     int longestWPI(vector<int>& hours) 
     {
        const size_t hours_length = hours.size();
        unordered_map<int, int> mp;
        int res = 0; 
        int score = 0; 
        
        for (int i = 0; i < hours_length; ++i) {
            hours[i] = hours[i] > 8 ? 1 : -1;
            score = score + hours[i];
            if (score > 0) {
                res = i + 1;
            } 
            else {
                if (mp.find(score) == mp.end()) {
                   mp[score] = i;
                }
                if (mp.find(score - 1) != mp.end()) {
                    res = max(res, i - mp[score - 1]);
                } 
            }
        }
         
        return res;
    }
};