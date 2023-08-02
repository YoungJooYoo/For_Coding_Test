class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) 
    {
        for (int i = 0; i < wordsDict.size(); i++) {
            mp[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) 
    {
        vector<int> wordIndex1 = mp[word1];
        vector<int> wordIndex2 = mp[word2];
        int index1 = 0;
        int index2 = 0;
        int minDistance = INT_MAX;
        
        while (index1 < wordIndex1.size() && index2 < wordIndex2.size()) {
            minDistance = min(minDistance, abs(wordIndex1[index1] - wordIndex2[index2]));
            if (wordIndex1[index1] < wordIndex2[index2]) {
                index1++;
            }
            else {
                index2++;
            }
        }
        
        return minDistance;
    }
    
private:
    unordered_map<string, vector<int>> mp;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */