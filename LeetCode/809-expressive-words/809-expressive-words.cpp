class Solution {
public:
       int expressiveWords(string s, vector<string>& words) 
       {
            int res = 0;
           
            for (const string& word : words) {
                if (check(s, word)) {
                    res++; 
                }
            }
   
         return res;
    }

    bool check(string s, string w) 
    {
        const size_t n = s.size();
        const size_t m = w.size();
        size_t j = 0;
        
        for (size_t i = 0; i < n; i++) {
            if (j < m && s[i] == w[j]) {
                j++;
            }
            else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
            else if (0 < i && i < n - 1 && s[i - 1] == s[i] && s[i] == s[i + 1]);
            else {
                return false;
            }
        }
        
        return j == m  ? true : false;
    }
};