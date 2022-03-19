class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_set<string> items = unordered_set<string>(supplies.begin(), supplies.end());
        
        while(true) {
            const size_t items_size_1 = items.size();
            for (size_t i = 0; i < recipes.size(); i++) { // 레시피에서 탐색 시작
                if (items.find(recipes[i]) != items.end()) { // 가져온 supplies에 레시피가 있는지 탐색
                    continue; // 레시피가 supplies에 있다면, continue
                }
                bool all_present = true; // 
                for (const string& item : ingredients[i]) {
                    if (items.find(item) == items.end()) { // ingredients의 값이 supplies에 있다면, 
                        all_present = false;
                        break;
                    }
                }
                if (all_present) {
                    items.insert(recipes[i]);
                }
            }
            const size_t items_size_2 = items.size();
            if (items_size_1 == items_size_2) {
                break;
            }
        }
        
        vector<string> res;
        
        for (string item: recipes) {
            if (items.find(item) != items.end()) {
                res.push_back(item);
            }
        }
        
        return res;
    }
};