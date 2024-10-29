class Solution 
{
public:
    vector<string> letterCasePermutation(string& s) 
    {   
        backtrack(s, 0);
        return mResult;
    }

private:
    void backtrack(string& s, const int index)
    {
        if (index == s.size())
        {
            mResult.push_back(s);
            return;
        }

        backtrack(s, index + 1);

        if (isalpha(s[index]))
        {
            s[index]  ^= 32;
            backtrack(s, index + 1);
            s[index]  ^= 32;
        }
    }

private:
    vector<string> mResult;
};

// https://leetcode.com/problems/letter-case-permutation/
