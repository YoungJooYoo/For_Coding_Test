class Solution {
public:
    bool canPermutePalindrome(string s) 
    {
        unordered_map<char, int> word;
        size_t odd_num_count = 0;
        
        
        for (size_t i = 0; i < s.size(); i++) {
            word[s[i]]++;
        }
       
        for (const auto& element : word) {
            if (element.second % 2 == 1) {
                odd_num_count++;
                if(odd_num_count > 1) {
                    return false;
                }
            }
        }         
        
        return true;    
    }
};
