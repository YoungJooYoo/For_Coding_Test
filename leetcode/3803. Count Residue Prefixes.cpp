class Solution
{
public:
    int residuePrefixes(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        const size_t LENGTH = s.size();
        string prefix;
        int residuePrefixCount = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            prefix += s[i];
            const unordered_set<char> distinctCharacters(prefix.begin(), prefix.end());
            const size_t distinctCount = distinctCharacters.size();
            const size_t remainder = prefix.size() % MOD_BASE;
            if (distinctCount == remainder)
            {
                ++residuePrefixCount;
            }
        }

        assert(residuePrefixCount >= 0);
        return residuePrefixCount;
    }

private:
    enum
    {
        MOD_BASE = 3,
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};

// https://leetcode.com/problems/count-residue-prefixes/description/
