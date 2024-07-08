class Solution 
{
public:
    string getEncryptedString(const string& s, const int k) 
    {
        const size_t LENGTH = s.size();
        string result;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const size_t idx = (i + k) % LENGTH;
            result.push_back(s[idx]);
        }

        return result;
    }
};

// https://leetcode.com/problems/find-the-encrypted-string/description/
