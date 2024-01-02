class Solution {
public:
    int findLUSlength(const string& a, const string& b) 
    {
        if (a == b) {
            return FAIL;
        }

        return max(a.size(),  b.size());

    }

private:
    enum { FAIL = -1 };
};

//  https://leetcode.com/problems/longest-uncommon-subsequence-i/description/
