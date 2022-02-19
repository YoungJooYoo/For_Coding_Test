class Solution {
public:
    bool removeOnes(vector<vector<int>>& g) 
    {
        for (size_t i = 0; i < g.size(); ++i) {
            for (size_t j = 0; j < g[i].size(); ++j) {
                if (g[i][j] ^ g[i][0] ^ g[0][j] ^ g[0][0]) {
                    return false;
                }
            }
        }
        return true;
    }
};