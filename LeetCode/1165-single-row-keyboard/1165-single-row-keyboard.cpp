class Solution {
public:
    int calculateTime(string keyboard, string word) 
    {
        unordered_map<char, int> position;
        
        int i = 0;
        for (const auto& elem : keyboard) {
            position[elem] = i;
            ++i;
        }
        
        int time = position[word[0]];
        for (size_t i = 1; i < word.size(); i++) {
            time += abs(position[word[i - 1]] - position[word[i]]);
        }
        
        return time;
    }
};