class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        size_t i = 0;
        size_t j = 0;
        int result = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                ++i;
                ++result;
            }
            ++j;
        }

        return result;
    }
};
