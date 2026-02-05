class Solution 
{
public:
    string reverseByType(string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        stack<char> alphabet;
        stack<char> specialChar;

        for (const char ch : s)
        {
            if (isalpha(ch))
            {
                alphabet.push(ch);
            }
            else
            {
                specialChar.push(ch);
            }
        }
        assert((alphabet.size() + specialChar.size()) == s.size());

        for (char& ch : s)
        {
            if (isalpha(ch))
            {
                assert(!alphabet.empty());
                ch = alphabet.top();
                alphabet.pop();
            }
            else
            {
                assert(!specialChar.empty());
                ch = specialChar.top();
                specialChar.pop();
            }
        }
       
        return s;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100
    };
};
// https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/description/
