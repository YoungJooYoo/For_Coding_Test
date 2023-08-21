class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) 
    {
        vector<string> result;
        string word;

        for (const auto& word : words) {
            stringstream sstream(word);
            string temp;
            while(getline(sstream, temp, separator)) {
                if (temp.size() != 0) result.push_back(temp);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/split-strings-by-separator/description/
