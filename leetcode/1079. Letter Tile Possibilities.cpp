class Solution 
{
public:
    int numTilePossibilities(const string& tiles)
    {
        for (const char c : tiles)
        {
            ++mFrequency[c];
        }
        
        numTilePossibilitiesHelperRecursive();
        
        return mResultCount;
    }

private:
    void numTilePossibilitiesHelperRecursive()
    {
        for (auto& entry : mFrequency)
        {
            if (entry.second > 0)
            {
                --entry.second;
                ++mResultCount;
                numTilePossibilitiesHelperRecursive();
                ++entry.second;
            }
        }
    }

private:
    unordered_map<char, int> mFrequency;
    int mResultCount = 0;
};


// https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17
