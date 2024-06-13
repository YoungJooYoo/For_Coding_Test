class Solution 
{
public:
    bool areNumbersAscending(const string& s) 
    {
        stringstream ss(s);
        string word;
        int num = INT_MIN;

        while (ss >> word)
        {
            string temp;
            for (const auto ch : word)
            {
                if (isdigit(ch) == true)
                {
                    temp += to_string(ch);
                }
            }
            if (!temp.empty())
            {
                const int tempNum = stoi(temp);
                if (num >= tempNum) 
                {
                    return false;
                }
                num = tempNum;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/description/
