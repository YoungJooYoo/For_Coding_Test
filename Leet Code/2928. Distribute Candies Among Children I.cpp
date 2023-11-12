class Solution {
public:
    int distributeCandies(const int n, const int limit) 
    {
        int count = 0;

        for (int i = 0; i <= limit; ++i) {
            for (int j = 0; j <= limit; ++j) {
                for (int k = 0; k <= limit; ++k) {
                    if (i + j + k == n) ++count;
                }
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/distribute-candies-among-children-i/description/
