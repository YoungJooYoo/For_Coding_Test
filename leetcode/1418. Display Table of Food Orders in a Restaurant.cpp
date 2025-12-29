class Solution
{
public:
    vector<vector<string>> displayTable(const vector<vector<string>>& orders) const
    {
        assert(MIN_ORDERS_LENGTH <= orders.size() && orders.size() <= MAX_ORDERS_LENGTH);

        set<string> foodItems;
        map<int, map<string, int>> ordersByTable;
        vector<vector<string>> displayTable;

        for (const auto& order : orders)
        {
            const int tableNumber = stoi(order[TABLE_INDEX]);
            const string& foodItem = order[FOOD_INDEX];
            foodItems.insert(foodItem);
            ++ordersByTable[tableNumber][foodItem];
            assert(order.size() == ORDER_FIELD_COUNT);
            assert(MIN_TABLE_NUMBER <= tableNumber && tableNumber <= MAX_TABLE_NUMBER);
            assert(MIN_ITEM_LENGTH <= foodItem.size() && foodItem.size() <= MAX_ITEM_LENGTH);
        }

        // Header row
        vector<string> row;
        row.push_back("Table");
        row.insert(row.end(), foodItems.begin(), foodItems.end());
        displayTable.push_back(row);

        // Data rows
        for (const auto& [tableNumber, foodCounts] : ordersByTable)
        {
            row.clear();
            row.push_back(to_string(tableNumber));
            for (const auto& food : foodItems)
            {
                const auto it = foodCounts.find(food);
                row.push_back(it != foodCounts.end() ? to_string(it->second) : "0");
            }
            displayTable.push_back(row);
        }

        return displayTable;
    }

private:
    enum
    {
        ORDER_FIELD_COUNT = 3,
        CUSTOMER_INDEX = 0,
        TABLE_INDEX = 1,
        FOOD_INDEX = 2,

        MIN_ORDERS_LENGTH = 1,
        MAX_ORDERS_LENGTH = 5 * 10000,
        MIN_TABLE_NUMBER = 1,
        MAX_TABLE_NUMBER = 500,
        MIN_ITEM_LENGTH = 1,
        MAX_ITEM_LENGTH = 20
    };
};

// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/

/*

### **문제 설명**
레스토랑 고객들의 주문 정보가 담긴 배열 `orders`가 주어집니다. 각 주문 정보는 `orders[i] = [customerName_i, tableNumber_i, foodItem_i]` 형태이며, 이는 고객의 이름, 테이블 번호, 그리고 주문한 음식을 의미합니다.

이 정보를 바탕으로 레스토랑의 **"주문 표시 테이블(display table)"**을 생성하여 반환하세요.

### **주문 표시 테이블 규칙**
1.  **구성**: 각 행은 특정 테이블이 각 음식 아이템을 몇 개 주문했는지를 나타냅니다.
2.  **첫 번째 행 (헤더)**: 
    *   첫 번째 열은 `"Table"`입니다.
    *   나머지 열은 모든 주문에 포함된 **음식 이름**들을 **알파벳 오름차순**으로 나열합니다.
3.  **데이터 행**:
    *   첫 번째 열은 **테이블 번호**입니다.
    *   나머지 열은 해당 테이블에서 각 음식을 주문한 수량입니다.
4.  **정렬 규칙**:
    *   고객의 이름은 결과 테이블에 포함되지 않습니다.
    *   테이블 번호(행)는 **숫자 크기순(오름차순)**으로 정렬되어야 합니다.
    *   음식 이름(열)은 **알파벳순**으로 정렬되어야 합니다.

---

### **예시 1**
**입력**: `orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]`

**출력**: `[["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]]`

**설명**:
*   3번 테이블: David가 Ceviche와 Fried Chicken을 주문했고, Rous가 Ceviche를 주문했습니다. (Ceviche: 2, Fried Chicken: 1)
*   5번 테이블: Carla가 Water와 Ceviche를 주문했습니다. (Water: 1, Ceviche: 1)
*   10번 테이블: Corina가 Beef Burrito를 주문했습니다. (Beef Burrito: 1)

---

### **제한 사항**
*   `1 <= orders.length <= 5 * 10^4`
*   `orders[i].length == 3`
*   `1 <= customerName_i.length, foodItem_i.length <= 20`
*   테이블 번호는 1에서 500 사이의 유효한 정수입니다.
*/
