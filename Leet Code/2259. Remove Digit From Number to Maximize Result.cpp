class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        string result = "0";

        for (size_t i = 0; i < number.size(); ++i) {
            if (number[i] == digit) {
                string temp = number.substr(0, i) + number.substr(i + 1, number.size());
                result = max(result, temp);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/
