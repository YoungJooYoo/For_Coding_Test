class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<int> copy = score;
        sort(copy.begin(), copy.end(), greater<int>());

        unordered_map<int, string> mp;
        int count = 1;
        
        for (const auto& s : copy) {
            if (count == 1) {
                mp[s] = "Gold Medal";
                ++count;
            }
            else if (count == 2) {
                mp[s] = "Silver Medal";
                ++count;
            }
            else if (count == 3) {
                mp[s] = "Bronze Medal";
                ++count;
            }
            else  {
                mp[s] = to_string(count);
                ++count;
            }
        }
        
        vector<string> result;
        for (auto& s : score) {
            result.push_back(mp[s]);
        }
        
        return result;
    }
};

// https://leetcode.com/problems/relative-ranks/description/
