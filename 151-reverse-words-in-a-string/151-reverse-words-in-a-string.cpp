class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string> vec;
        stringstream str(s);
        string word;
        string res;
        
        while (str >> word) { // store separated words in vector
            vec.push_back(word); // 공백을 제거하고 단어단위로 배열에 넣기
        }
        
        reverse(vec.begin(), vec.end());
        
        for (const auto&it : vec) { // 배열의 저장된 문자열을 이어 붙인다.
            res+=" "+it;
        }
        res.erase(0, 1); // 리버스 후, 시작점은 항상 공백이 들어가 있다. 그래서 공백을 제거한다.
        
        return res;
    }
};