class Solution {
public:
    void get_factors(int num)
    {
        for (size_t i = 1; i <= num; ++i) {
            if (num % i == 0) {
                freq[i]++;
            }
        }
    }

    int commonFactors(int a, int b) 
    {
        int result = 0;

        get_factors(a);
        get_factors(b);

        for (const auto& elem : freq) {
            if (elem.second >= 2) {
                ++result;
            }
        }

        return result;
    }

private:
    unordered_map<int, int> freq;
};

// https://leetcode.com/problems/number-of-common-factors/description/
