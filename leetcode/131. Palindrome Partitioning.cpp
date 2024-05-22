class Solution 
{
public:
    vector<vector<string>> partition(const string& s) 
    {
        getPalindromePartition(s, 0);
        return mResult;
    }

private:
    void getPalindromePartition(const string& s, int start)
    {
        const int LENGTH = s.size();
        if (LENGTH == start)
        {
            mResult.push_back(mCurrentPartition);
        }

        for (int end = start; end < LENGTH; ++end)
        {
            if (isPalindrome(s, start, end) == true)
            {
                mCurrentPartition.push_back(s.substr(start, end - start + 1));
                getPalindromePartition(s, end + 1);
                mCurrentPartition.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            ++left;
            --right;
        }

        return  true;
    }


private:
    vector<vector<string>> mResult;
    vector<string> mCurrentPartition;
};

// https://leetcode.com/problems/palindrome-partitioning/description/?envType=daily-question&envId=2024-05-22
