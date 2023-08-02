class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        vector<vector<int>> result;
        map<int, int> items;
        
        for (const auto& item1 : items1) {
            items[item1[0]] = item1[1];
        }
        for (const auto& item2 : items2) {
            const int left = item2[0];
            const int right = item2[1];
            if (items[left] != 0) items[left] += right;
            else items[left] = right;
        }

        for (const auto& item : items) {
            result.push_back({ item.first, item.second });
        }

        return result;
    }
};

// https://leetcode.com/problems/merge-similar-items/description/
