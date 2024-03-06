class Solution {
public:
    string largestGoodInteger(const string& num) 
    {
        string result = "";
        
        for (size_t i = 0; i < num.size() - 2; ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string temp = num.substr(i, 3);
                if (temp > result) {
                    result = temp;
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/largest-3-same-digit-number-in-string/
