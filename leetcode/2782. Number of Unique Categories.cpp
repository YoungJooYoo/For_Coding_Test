/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution 
{
public:
    int numberOfCategories(const int n, CategoryHandler* const categoryHandler) 
    {
        vector<int> categories(n, 0);
        
        // 초기화: 각 요소를 자신과 동일한 그룹으로 설정
        for (int i = 0; i < n; ++i) 
        {
            categories[i] = i;
        }

        // 그룹 병합
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) // i == j를 건너뛰고, 필요없는 반복을 피합니다.
            {  
                if (categoryHandler->haveSameCategory(i, j)) 
                {
                    categories[j] = categories[i];  // i의 그룹을 j에 적용
                }
            }
        }

        // 고유한 카테고리 개수 계산
        set<int> uniqueCategories(begin(categories), end(categories));
        return uniqueCategories.size();
    }

};

// https://leetcode.com/problems/number-of-unique-categories/description/

/*

### 문제 설명:

정수 `n`과 `CategoryHandler` 클래스의 객체 `categoryHandler`가 주어집니다.

`n`개의 요소가 있으며, 각 요소는 번호가 0부터 `n - 1`까지 매겨집니다. 각 요소에는 카테고리가 있으며, 여러분의 작업은 고유한 카테고리의 수를 찾는 것입니다.

`CategoryHandler` 클래스에는 다음과 같은 함수가 포함되어 있습니다:

- `boolean haveSameCategory(integer a, integer b)`: `a`와 `b`가 동일한 카테고리에 속하면 true를 반환하고, 그렇지 않으면 false를 반환합니다. 또한, `a` 또는 `b`가 유효하지 않은 번호(즉, 0보다 작거나 `n`보다 크거나 같은 경우)인 경우 false를 반환합니다.

여러분의 목표는 고유한 카테고리의 수를 반환하는 것입니다.

### 예제:

**예제 1:**
- 입력: `n = 6`, `categoryHandler = [1,1,2,2,3,3]`
- 출력: `3`
- 설명: 이 예제에서는 6개의 요소가 있습니다. 첫 번째와 두 번째 요소는 1번 카테고리에 속하고, 세 번째와 네 번째 요소는 2번 카테고리에 속하며, 마지막 두 요소는 3번 카테고리에 속합니다. 따라서 고유한 카테고리의 수는 3입니다.

**예제 2:**
- 입력: `n = 5`, `categoryHandler = [1,2,3,4,5]`
- 출력: `5`
- 설명: 이 예제에서는 5개의 요소가 있습니다. 각 요소는 고유한 카테고리에 속하므로, 고유한 카테고리의 수는 5입니다.

**예제 3:**
- 입력: `n = 3`, `categoryHandler = [1,1,1]`
- 출력: `1`
- 설명: 이 예제에서는 3개의 요소가 있으며, 모두 동일한 카테고리에 속합니다. 따라서 고유한 카테고리의 수는 1입니다.

### 제약 조건:

- `1 <= n <= 100`

이 문제는 주어진 요소들 사이의 고유한 카테고리의 수를 확인하는 것을 목표로 합니다. 주어진 `haveSameCategory` 함수를 사용하여 같은 카테고리에 속하는 요소들을 그룹화한 다음, 이러한 그룹의 수를 계산해야 합니다. 

이를 해결하기 위해, 요소 간의 관계를 표현할 수 있는 유니온 파인드(Union-Find) 자료구조를 사용할 수 있습니다.

*/
