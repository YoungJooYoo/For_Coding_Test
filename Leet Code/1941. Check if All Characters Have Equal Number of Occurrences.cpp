class Solution {
public:
    bool areOccurrencesEqual(const string &s) 
    {
        map<char, int> freq;

        // Count the frequency of each character in the string
        for (const char c : s) {
            ++freq[c];
        }
        
        // Insert the frequency of each character into the set
        set<int> size;
        for (const auto& elem : freq) {
            size.insert(elem.second);
        }

        // If the size of the set is 1, all characters have the same frequency
        return size.size() == 1 ? true : false;
    }
};

// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/
