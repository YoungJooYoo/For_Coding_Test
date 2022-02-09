class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hist; 
        
        for (auto c:s)
            hist[c]++; 
        
        int odd=0;         
        for (auto h:hist)
        {
            if (h.second%2 ==1 )
            {
                 odd++;
                if(odd>1) 
                    return false;
            }
        }                 
        return true;         
    }
};