class Solution {
public:
    string sortSentence(string s) 
    {
        stringstream ss(s); // 공백전까지 문자열 단위를 끊어 온다. 
        string word;
        string result;
        vector<string> vec(9);
        
        while (ss >> word) { // 즉 띄어쓰기 단어로 문자열 분해
            vec[word.back() - '1'] = word.substr(0, word.size() - 1); // 문자열 저장하는 벡터에, 숫자의 순서대로 저장한다. 저장하는 문자열은 word에서 숫자 제거한 문자열
        }
        
        int i = 0;
        while (vec[i] != "") { // 빈문자열 아니면, 문자열 누적해서 문자열 만들기
            result += " " + vec[i];
            i++;
        }
        
        return result.substr(1);
    }
};