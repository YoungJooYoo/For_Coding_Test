class Solution {
public:
    bool checkZeroOnes(const string& s) 
    {
        const size_t STR_LENGTH = s.size();

        size_t one_max_length = 0;
        size_t zero_max_length = 0;
        size_t one_curr_length = 0;
        size_t zero_curr_length = 0;

        for (size_t i = 0; i < STR_LENGTH; ++i) {
            if (s[i] == '1') {
                ++one_curr_length;
                zero_curr_length ^= zero_curr_length;
                one_max_length = max(one_max_length, one_curr_length);
            }
            else {
                ++zero_curr_length;
                one_curr_length ^= one_curr_length;
                zero_max_length = max(zero_max_length, zero_curr_length);
            }
        }

        return one_max_length > zero_max_length ? true : false;
    }
};

// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
