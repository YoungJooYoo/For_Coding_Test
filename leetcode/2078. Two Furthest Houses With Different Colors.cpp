class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        const size_t ARRAY_LENGTH = colors.size();
        int max_length = 0;

        for (int i = 0; i < ARRAY_LENGTH - 1; ++i) {
            for (int j = i + 1; j < ARRAY_LENGTH; ++j) {
                if (colors[i] != colors[j]) {
                    max_length = max(max_length, j - i);
                }
            }
        }

        return max_length;    
    }
};

// https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/
