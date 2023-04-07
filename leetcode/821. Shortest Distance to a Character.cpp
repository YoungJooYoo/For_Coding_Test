class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        const size_t SIZE = s.size();
        vector<int> result (SIZE, SIZE);
        int pos = -SIZE;

        for (size_t i = 0; i < SIZE; ++i) {
            if (s[i] == c) pos = i;
            result[i] = i - pos;
        }

        for (int i = pos - 1; i >= 0; --i) {
            if (s[i] == c) pos = i;
            result[i] = min(abs(i - pos), result[i]);
        }

   
        return result;
    }
};

// https://leetcode.com/problems/shortest-distance-to-a-character/description/
