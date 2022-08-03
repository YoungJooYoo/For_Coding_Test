class Solution 
{
public:
    bool is_palindromic (const string& str)
    {
        const size_t STR_SIZE = str.size();

        int i = 0;
        int j = STR_SIZE - 1;
        
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int countSubstrings(string& s) 
    {
        const size_t STR_SIZE = s.size();
        int count = 0;
        
        // 서브스트링 구하면서, palidromic 체크
        for (size_t i = 0; i < STR_SIZE; i++) {
            string temp;
            for (size_t j = i; j < STR_SIZE; j++) {
                temp += s[j];
                if (is_palindromic(temp) == true) {
                    count++;
                }
            }
        }
        
        return count;
    }
};