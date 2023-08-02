class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        const int SIZE = s.size();
        int low = 0;
        int high = SIZE;
        vector<int> result(SIZE + 1, 0);

        for (size_t i = 0; i < SIZE; ++i) {
            if (s[i] == 'D') result[i] = high--;
            else if (s[i] == 'I') result[i] = low++;
            else assert(false);    
        }
        result[SIZE] = low; // or high is okay

        return result;
    }
};

// https://leetcode.com/problems/di-string-match/description/
