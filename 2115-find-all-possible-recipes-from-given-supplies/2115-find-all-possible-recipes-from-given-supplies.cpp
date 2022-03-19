class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_set<string> items = unordered_set<string>(supplies.begin(), supplies.end());
        // 배열값 -> 해시로 넣어서 성능 향상
        
        while(true) {
            const size_t items_size_1 = items.size();
            for (size_t i = 0; i < recipes.size(); i++) { // 레시피에서 탐색 시작
                if (items.find(recipes[i]) != items.end()) { // 가져온 supplies에 레시피가 있는지 탐색
                    continue; // 레시피가 supplies에 있다면, continue
                }
                bool is_exist_all_items = true; // 
                for (const string& item : ingredients[i]) {
                    if (items.find(item) == items.end()) { // ingredients의 값이 supplies에 있다면, 
                        is_exist_all_items = false; 
                        break;
                    }
                }
                if (is_exist_all_items == true) {
                    items.insert(recipes[i]);
                }
            }
            const size_t items_size_2 = items.size();
            if (items_size_1 == items_size_2) { // 만들어야하는 레시피 목록 음식과, supplies재료로 음식이 추가된 후 갯수가 서로 일치하는 경우
                break;
            }
        }
        
        vector<string> result;
        
        for (const string& recipe: recipes) {
            if (items.find(recipe) != items.end()) {
                result.push_back(recipe);
            }
        }
        
        return result;
    }
};