class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        string temp = s + s;
        temp = temp.substr(1, temp.size() - 2); // 맨 앞과 맨뒤 문자열 제거
        return temp.find(s) == string::npos ? false : true;
    }
};

// abab abab
// bab aba
// ba ab