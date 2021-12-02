class Solution {
private:
    string reverse_s(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]) ;
            start++;
            end--;
        }
        
        return s;
    }
    
public:
    string reverseStr(string s, int k) {
        const size_t len = s.size();
        size_t i = 0;
        
        while (i < len) {
            if (i + k - 1 < len) { // i + k - 1은, 
               reverse_s(s, i, i + k - 1); 
            }
            else {
               reverse_s(s, i, len - 1);
            }
            i = i + (2 * k);
        }
        
        return s;
    }
};