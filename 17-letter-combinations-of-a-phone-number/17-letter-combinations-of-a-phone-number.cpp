class Solution {
public:
    void dfs(const string& digits, string& path, int index)
    {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }
        
        for (const char& num : dial[digits[index] - '0']) { // digits[index] - '0' =  digits의 각 숫자 하나씩 접근,  그 숫자로 dial[인덱스] 접근
            path[index] = num;
            dfs(digits, path, index + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if (digits.length() == 0) {
            return result;
        }
        
        string path = digits;
        
        dfs(digits, path, 0);
        
        return result;
    }
    
private:
    enum { ALPHABET_LENGTH = 26 };
    vector<string> dial = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"}; // 0,1,2,3.4,5,6,7,8,9
    vector<string> result;
};