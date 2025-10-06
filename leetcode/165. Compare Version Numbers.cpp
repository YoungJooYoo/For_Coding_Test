class Solution 
{
public:
    int compareVersion(const string& version1, const string& version2) 
    {

        const vector<int> revisions1 = parseVersionString(version1);
        const vector<int> revisions2 = parseVersionString(version2);
        const size_t len1 = revisions1.size();
        const size_t len2 = revisions2.size();
        const size_t max_len = max(len1, len2);

        for (size_t i = 0; i < max_len; ++i) 
        {
            const int rev1 = (i < len1) ? revisions1[i] : 0;
            const int rev2 = (i < len2) ? revisions2[i] : 0;
            if (rev1 > rev2) 
            {
                return VERSION1_IS_GREATER;
            }
            if (rev1 < rev2) 
            {
                return VERSION1_IS_LESS;
            }
        }

        return ARE_SAME;
    }

private:
    static vector<int> parseVersionString(const string& versionStr) 
    {
        vector<int> revisions;
        stringstream ss(versionStr);
        string revisionSegment;

        while (getline(ss, revisionSegment, '.')) 
        {
            revisions.push_back(stoi(revisionSegment));
        }

        return revisions;
    }

    enum ComparisonResult
    {
        ARE_SAME = 0,
        VERSION1_IS_GREATER = 1,
        VERSION1_IS_LESS = -1,
    };
};

// https://leetcode.com/problems/compare-version-numbers/?envType=daily-question&envId=2025-09-23
