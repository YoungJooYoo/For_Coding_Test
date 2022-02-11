class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) 
    {
        int min_distance = INT_MAX;
        int distance_1 = -1;
        int distance_2 = -1;
        
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1){
                distance_1 = i;
                if (distance_2 != -1) {
                    min_distance = min(min_distance, distance_1 - distance_2);
                }
            }
            else if (wordsDict[i] == word2) {
                distance_2 = i;
                if (distance_1 != -1) {
                    min_distance = min(min_distance, distance_2 - distance_1);
                }
            }
        }
        
        return min_distance;
    }
};