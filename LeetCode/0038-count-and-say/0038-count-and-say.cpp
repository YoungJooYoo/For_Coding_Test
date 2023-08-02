class Solution 
{
public:
    string countAndSay(int n) 
    {
        if (n == 0) {
            return "";
        }
        
        string result = "1";
        
        while (--n != 0) {
            string cur = "";
            for (int i = 0; i < result.size(); i++) {
                int count = 1;
                 while ((i + 1 < result.size()) && (result[i] == result[i + 1])){
                    count++;    
                    i++;
                }
                cur += to_string(count) + result[i];
            }
            
            result = cur;
        }
        
        return result;
    }
};
