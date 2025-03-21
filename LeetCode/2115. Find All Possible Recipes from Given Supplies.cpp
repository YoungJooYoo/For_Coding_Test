class Solution 
{
public:
    vector<string> findAllRecipes(const vector<string>& recipes,
                                  const vector<vector<string>>& ingredients,
                                  const vector<string>& supplies) const 
    {
        
        assert(recipes.size() == ingredients.size());
        assert(supplies.size() >= MIN_LIST_LENGTH && supplies.size() <= MAX_LIST_LENGTH);
        assert(ingredients.size() >= MIN_LIST_LENGTH && ingredients.size() <= MAX_LIST_LENGTH);

        unordered_set<string> availableSupplies(supplies.begin(), supplies.end());
        unordered_set<string> createdRecipes;
        bool bProgress = true;

        while (bProgress == true) 
        {
            bProgress = false;
            for (size_t i = 0; i < recipes.size(); ++i) 
            {
                if (createdRecipes.find(recipes[i]) != createdRecipes.end()) // 이미 만들어진 요리법은 건너뜁니다.
                {
                    continue;
                }
                    
                bool bCanCreate = true;
                for (size_t j = 0; j < ingredients[i].size(); ++j) // 현재 요리법을 만드는데 필요한 모든 재료가 availableSupplies에 존재하는지 검사합니다.
                {
                    if (availableSupplies.find(ingredients[i][j]) == availableSupplies.end()) 
                    {
                        bCanCreate = false;
                        break;
                    }
                }
                // 재료가 모두 있다면, 해당 요리법을 만들 수 있습니다.
                if (bCanCreate == true) 
                {
                    availableSupplies.insert(recipes[i]);  // 다른 요리법의 재료로 활용 가능
                    createdRecipes.insert(recipes[i]);
                    bProgress = true;
                }
            }
        }
        
        return vector<string>(createdRecipes.begin(), createdRecipes.end());
    }
    
private:
    enum 
    {
        MIN_N = 1,
        MAX_N = 100,
        MIN_LIST_LENGTH = 1,
        MAX_LIST_LENGTH = 100,
        MIN_STR_LENGTH = 1,
        MAX_STR_LENGTH = 10
    };
};


// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

/*


**2115. 주어진 재료로 만들 수 있는 모든 가능한 요리법 찾기**

**난이도:** 중간

**문제 설명:**  
n개의 서로 다른 요리법에 대한 정보가 주어집니다.  
문자열 배열 **recipes**와 2차원 문자열 배열 **ingredients**가 주어지며,  
i번째 요리법의 이름은 **recipes[i]**이고, **ingredients[i]**에 있는 모든 필요한 재료가 있다면 해당 요리법을 만들 수 있습니다.  
요리법 자체가 다른 요리법의 재료가 될 수도 있습니다. 즉, **ingredients[i]**에는 **recipes**에 포함된 문자열이 있을 수 있습니다.

또한, 처음 가지고 있는 모든 재료가 담긴 문자열 배열 **supplies**가 주어지며, 이 재료들은 무한히 공급됩니다.

만들 수 있는 모든 요리법의 리스트를 반환하세요. 결과는 임의의 순서로 반환해도 됩니다.

**주의:** 두 요리법이 서로의 재료 목록에 포함될 수도 있습니다.

---

**예제 1:**

- **입력:**  
  recipes = ["bread"]  
  ingredients = [["yeast","flour"]]  
  supplies = ["yeast","flour","corn"]

- **출력:** ["bread"]

- **설명:**  
  "bread"는 재료 "yeast"와 "flour"가 있으므로 만들 수 있습니다.

---

**예제 2:**

- **입력:**  
  recipes = ["bread","sandwich"]  
  ingredients = [["yeast","flour"],["bread","meat"]]  
  supplies = ["yeast","flour","meat"]

- **출력:** ["bread","sandwich"]

- **설명:**  
  "bread"는 재료 "yeast"와 "flour"로 만들 수 있고,  
  "sandwich"는 재료 "meat"와 요리법 "bread" (즉, 만들어진 "bread")로 만들 수 있습니다.

---

**예제 3:**

- **입력:**  
  recipes = ["bread","sandwich","burger"]  
  ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]]  
  supplies = ["yeast","flour","meat"]

- **출력:** ["bread","sandwich","burger"]

- **설명:**  
  "bread"는 재료 "yeast"와 "flour"로 만들 수 있고,  
  "sandwich"는 재료 "meat"와 만들어진 "bread"로 만들 수 있으며,  
  "burger"는 재료 "meat"와 만들어진 "bread"와 "sandwich"로 만들 수 있습니다.

---

**제약 조건:**

- n == recipes.length == ingredients.length  
- 1 <= n <= 100  
- 1 <= ingredients[i].length, supplies.length <= 100  
- 1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10  
- recipes[i], ingredients[i][j], supplies[k]는 모두 소문자 영어 알파벳으로만 구성됩니다.  
- recipes와 supplies에 포함된 모든 값은 서로 유일합니다.  
- 각 ingredients[i]에는 중복된 값이 없습니다.

---
*/
