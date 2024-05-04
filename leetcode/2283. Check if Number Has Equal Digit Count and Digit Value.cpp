class Solution {
public:
    bool digitCount(const string& num) 
    {
        map<int, int> freq_index;
        map<int, int> freq_num;
    
        for (int i = 0; i < num.size(); ++i) {
            const int NUMBER = num[i] - '0';
            if (NUMBER != 0) freq_index[i] = NUMBER;
            ++freq_num[NUMBER];
        }
        
        return (freq_index == freq_num) ? true : false;
    }
};

// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/
