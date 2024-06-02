class Solution 
{
public:
    int minimumChairs(const string& s) 
    {
        const size_t LENGTH = s.size();
        int result = 0;
        int temp = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (s[i] == 'E')
            {
                ++temp;
            }
            else // s[i] == L
            {
                --temp;
            }
            result = max(result, temp);
        }
        
        return result;
    }
};
// https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/
