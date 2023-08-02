class Solution {
public:
    bool rotateString(string s, string g) 
    {
        if(s.length() != g.length()) {
            return false;
        }
        
        if((s + s).find(g) != string::npos) {
            return true;
        }
        
        return false;
    }
};