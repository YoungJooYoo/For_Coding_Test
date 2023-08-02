class Solution {
private:
    int alphabet_count[26] {0, }; // a to z, A to Z -> 52
    int alphabet_count2[26] {0, }; // a to z, A to Z -> 52
    
public:
    bool isAnagram(string s, string t) {
        for(size_t i = 0; i < s.size(); i++) {
            alphabet_count[s[i] - 'a']++;
        }
        for(size_t i = 0; i < t.size(); i++) {
            alphabet_count2[t[i] - 'a']++;
        }
        for(size_t i = 0; i < 26; i++) {
            if(alphabet_count[i] != alphabet_count2[i]) {
                return false;
            }
        }
        
        return true;
    }
};