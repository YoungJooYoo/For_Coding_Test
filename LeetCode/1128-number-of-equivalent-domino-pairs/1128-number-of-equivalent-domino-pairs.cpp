class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        map<pair<int, int>, int> freq;
        int seen = 0;
        
        for (auto& domino : dominoes) {
            sort(domino.begin(), domino.end());
            seen += freq[make_pair(domino[0], domino[1])]++;
        }
        
        return seen;
    }
};