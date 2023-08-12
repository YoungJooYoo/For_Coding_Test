class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const size_t n = candyType.size();
        unordered_set<int> st(candyType.begin(), candyType.end());
        if (st.size() >= n / 2) return n / 2;
        return st.size();
    }
};

// https://leetcode.com/problems/distribute-candies/description/
