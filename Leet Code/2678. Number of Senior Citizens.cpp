class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
       int count = 0;
       
       for (const auto& detail : details) {
           string temp = "";
           temp += detail[11];
           temp += detail[12];
           stoi(temp) > 60 ? ++count : count;
       } 

       return count;
    }
};

// https://leetcode.com/problems/number-of-senior-citizens/description/
