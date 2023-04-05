class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        while(s.find(part) !=  string::npos) {
            s.erase(s.find(part), part.size());
        }
        
        return s;
    }
};

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
