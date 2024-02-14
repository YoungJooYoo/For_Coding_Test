class Solution {
public:
    int numberCount(const int a, const int b) 
    {
        int count = b - a + 1;

        for (int i = a; i <= b; ++i) {
            const string num = to_string(i);
            unordered_set<char> freq(num.begin(), num.end());
            if (num.size() != freq.size()) --count;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-numbers-with-unique-digits-ii/
