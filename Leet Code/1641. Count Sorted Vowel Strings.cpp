class Solution {
public:
    int countVowelStrings(int n) {
        if(n == 0) return 0;
        
        // Number of strings of length 1 ending on: a, e, i, o, u
        array<int, 5> counts = { 1, 1, 1, 1, 1 };
        
        for (int i = 1; i < n; ++i) {
            // Only one string ending on 'a' on each iteration. Start with 1.`
            for (int j = 1; j < 5; ++j) {
                counts[j] += counts[j - 1];
            }
        }
        
        return accumulate(counts.begin(), counts.end(), 0);
    }
};

/*

n에 따른 누적개수

    a       e       i        o      u
	1       1       1        1      1
	1       2       3        4      5
	1       3       6       10     15

*/

// https://leetcode.com/problems/count-sorted-vowel-strings/description/
