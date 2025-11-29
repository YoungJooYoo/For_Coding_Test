class Solution 
{
public:
    string convertNumber(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        const size_t LENGTH = s.size();
        string result;

        for (size_t i = 0; i < LENGTH;)
        {
            assert('a' <= s[i] && s[i] <= 'z');
            bool bMatched = false;
            for (const int len : {5, 4, 3})
            {
                if (i + len <= LENGTH)
                {
                    const string sub = s.substr(i, len);
                    const auto it = mTable.find(sub);
                    if (it != mTable.end())
                    {
                        result.push_back(it->second);
                        i += len;
                        bMatched = true;
                        break;
                    }
                }
            }
            if (bMatched == false)
            {
                ++i;
            }
        }   

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_SUBSTR_LENGTH = 3,
        MAX_SUBSTR_LENGTH = 5
    };
    
    const unordered_map<string, char> mTable = 
    {
        {"zero", '0'},
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };
};
// https://leetcode.com/problems/convert-number-words-to-digits/description/
