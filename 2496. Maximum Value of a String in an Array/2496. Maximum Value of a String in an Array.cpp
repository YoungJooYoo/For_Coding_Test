class Solution {
public:
    int findValue(string str)
    {
        int result = 0;

        for (size_t i = 0; i <str.size(); ++i) {
            if (str[i] < '0' || str[i] > '9') {
                return str.size();
            }
            result = (result * 10) + (str[i] - '0');
        }

        return result;
    }
    
    int maximumValue(vector<string>& strs) 
    {
        int ans = 0;

        for (const auto& str: strs) {
            ans = max(ans, findValue(str));
        }

        return ans;
    }
};

// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/
