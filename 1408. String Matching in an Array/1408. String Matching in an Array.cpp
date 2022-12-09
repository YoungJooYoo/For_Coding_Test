class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        set<string> result;

        for (const auto& word : words) 
        {
            for (const auto& str : words) 
            {
                if (word == str) continue;
                else if (word.find(str) != -1) 
                {
                    result.insert(str);
                }
            }
        }

        return vector<string> (result.begin(), result.end());    
    }
};
