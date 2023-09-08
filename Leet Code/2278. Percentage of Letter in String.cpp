class Solution {
public:
    int percentageLetter(const string s, const char letter) 
    {
        int count = 0;

        for (const auto& ch : s) {
            if (letter == ch) ++count;
        }

        return (count * 100) / s.size();
    }
};
