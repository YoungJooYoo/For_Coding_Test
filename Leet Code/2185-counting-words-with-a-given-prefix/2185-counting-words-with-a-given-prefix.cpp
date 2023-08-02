class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int count = 0;
        
        for (const auto& word : words) {
            if (word.substr(0, pref.size()) == pref) {
                count++;
            }
        }
        
        return count;
    }
};