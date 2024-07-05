class Solution {
public:
    string betterCompression(const string& compressed) 
    {
        string result;
        char currentChar;
        string length;
        map<char, int> sortedCompressed;

        for (const char ch : compressed)
        {
            if (isdigit(ch))
            {
                length.push_back(ch);
            }
            else
            {
                if (!length.empty())
                {
                    sortedCompressed[currentChar] += stoi(length);
                    length.clear();
                }
                currentChar = ch;
            }
        }
        // 마지막 문자와 빈도 추가
        if (!length.empty())
        {
            sortedCompressed[currentChar] += stoi(length);
        }

        for (const auto& elem: sortedCompressed)
        {
            result += elem.first;
            result += to_string(elem.second);
        }

        return result;
    }
};

// https://leetcode.com/problems/better-compression-of-string/description/
