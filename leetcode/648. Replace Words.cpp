class Solution 
{
public:
    string replaceWords(const vector<string>& dictionary, const string& sentence) 
    {
        // 사전을 set으로 변환하여 빠른 검색을 가능하게 함
        const unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<string> replacedSentence;
        istringstream iss(sentence);
        string temp;
        
        while (iss >> temp) 
        {
            string prefix = "";
            bool found = false;

            // 단어의 접두사를 찾음
            for (int i = 1; i <= temp.length(); ++i) 
            {
                prefix = temp.substr(0, i);
                if (dict.find(prefix) != dict.end()) 
                {
                    replacedSentence.push_back(prefix);
                    found = true;
                    break;
                }
            }

            // 접두사를 찾지 못했을 경우 원래 단어를 추가
            if (!found) 
            {
                replacedSentence.push_back(temp);
            }
        }

        // 벡터를 공백으로 구분된 문자열로 변환
        string result;
        for (int i = 0; i < replacedSentence.size(); ++i) 
        {
            if (i > 0) 
            {
                result += " ";
            }
            result += replacedSentence[i];
        }

        return result;
    }
};

// https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07
