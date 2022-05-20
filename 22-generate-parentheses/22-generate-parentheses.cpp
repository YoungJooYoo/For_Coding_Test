class Solution {
public:
    void recursive(string curr, int open, int close) 
    {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        
        if (open > 0) {
            recursive(curr + "(", open - 1, close + 1);
        } 
        if (close > 0) {
            recursive(curr + ")", open, close - 1);
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        recursive("", n, 0);
        return res;
    }
    
private:
    vector<string> res;
};