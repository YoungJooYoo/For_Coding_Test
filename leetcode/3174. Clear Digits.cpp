class Solution {
public:
    string clearDigits(const string& s) 
    {
        string result;

        for (const auto& ch : s)
        {
            if (isdigit(ch) == false)
            {
                result += ch;
            }
            else
            {
                result.pop_back();
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/clear-digits/
