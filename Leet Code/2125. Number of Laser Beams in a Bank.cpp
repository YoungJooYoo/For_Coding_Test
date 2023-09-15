class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int result = 0;
        int prev = 0;

        for (const auto& elem : bank) {
            int cnt = count(elem.begin(), elem.end(), '1');
            if (cnt > 0) {
                result += prev * cnt;
                prev = cnt;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
