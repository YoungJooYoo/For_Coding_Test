class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        const size_t SIZE = items.size();
        int count = 0;

        if (ruleKey == "type") {
            for (size_t i = 0; i < SIZE; ++i) {
                if (items[i][0] == ruleValue) ++count;
            }
        } 
        else if (ruleKey == "color") {
            for (size_t i = 0; i < SIZE; ++i) {
                if (items[i][1] == ruleValue) ++count; 
            }
        }
        else if (ruleKey == "name") {
            for (size_t i = 0; i < SIZE; ++i) {
                if (items[i][2] == ruleValue) ++count; 
            }
        }   

        return count;
    }
};

// https://leetcode.com/problems/count-items-matching-a-rule/description/
