class Solution 
{
public:
    string reformat(const string& s) const 
    {
        string digits = "";
        string letters = "";

        for (const char& c : s) 
        {
            if (isdigit(c)) digits += c;
            else letters += c;
        }

        const int numDigits = digits.size();
        const int numLetters = letters.size();
        string result = "";

        if (abs(numDigits - numLetters) > 1) 
        {
            return result;
        }
        if (numDigits < numLetters) 
        {
            swap(digits, letters);
        }

        const int minLength = min(numDigits, numLetters);
        int index = 0;
        while (index < minLength) 
        {
            result += digits[index];
            result += letters[index];
            ++index;
        }
        if (abs(numDigits - numLetters) == 1) 
        {
            result += digits[max(numDigits, numLetters) - 1];
        }

        return result;
    }
};


// https://leetcode.com/problems/reformat-the-string/
