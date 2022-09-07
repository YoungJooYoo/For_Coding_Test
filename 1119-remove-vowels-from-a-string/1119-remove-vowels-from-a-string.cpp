class Solution {
public:
    string removeVowels(string s) 
    {
        string result;
        
        for (const char& ch : s) {
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                result += ch;
            }
        }
        
        return result;
    }
};