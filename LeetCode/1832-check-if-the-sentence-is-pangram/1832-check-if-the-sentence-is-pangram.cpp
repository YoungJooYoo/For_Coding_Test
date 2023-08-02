class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        vector<int> alphabet(26, 0); // 알파벳 소문자 26개 담는 배열
        
        for (const char& ch : sentence) {
            alphabet[ch - 'a']++;
        }
        for (const int& ele : alphabet) {
            if (ele == 0) {
                return false;
            }
        }
            
        return true;
    }
};