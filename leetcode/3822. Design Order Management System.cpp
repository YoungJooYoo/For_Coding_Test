class OrderManagementSystem 
{
public:
    OrderManagementSystem() 
    {
        
    }
    
    void addOrder(const int orderId, const string& orderType, const int price) 
    {
        assert(MIN_ODERID <= orderId && orderId <= MAX_ODERID);
        assert(orderType == "buy" || orderType == "sell");
        assert(MIN_PRICE <= price && price <= MAX_PRICE);
        assert(mOrderInfo.find(orderId) == mOrderInfo.end());

        const pair<string, int> temp(orderType, price);
        mOrderInfo[orderId] = temp;
    }
    
    void modifyOrder(const int orderId, const int newPrice) 
    {
        assert(MIN_ODERID <= orderId && orderId <= MAX_ODERID);
        assert(MIN_PRICE <= newPrice && newPrice <= MAX_PRICE);
        assert(mOrderInfo.find(orderId) != mOrderInfo.end());

        mOrderInfo[orderId].second = newPrice;
    }
    
    void cancelOrder(const int orderId) 
    {
        assert(MIN_ODERID <= orderId && orderId <= MAX_ODERID);
        assert(mOrderInfo.find(orderId) != mOrderInfo.end());

        mOrderInfo.erase(orderId);
    }
        
    vector<int> getOrdersAtPrice(const string& orderType, const int price) const
    {
        assert(MIN_PRICE <= price && price <= MAX_PRICE);
        assert(orderType == "buy" || orderType == "sell");

        const pair<string, int> temp(orderType, price);
        vector<int> result;
        for (const auto& oderInfo : mOrderInfo)
        {
            if (oderInfo.second == temp)
            {
                result.push_back(oderInfo.first);
            }
        }

        return result;
    }

private:
    unordered_map<int, pair<string, int>> mOrderInfo; // orderID - orderType - price

    enum
    {
        MIN_ODERID = 1,
        MAX_ODERID = 2000,
        MIN_PRICE = 1,
        MAX_PRICE = 1000000000
    };
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */

 /*
 
https://leetcode.com/problems/design-order-management-system/description/
### 3822. 주문 관리 시스템 설계 (Design Order Management System)

**문제 설명**
거래 플랫폼을 위한 간단한 주문 관리 시스템을 설계해야 합니다.

각 주문은 `orderId`(주문 ID), `orderType`("buy" 또는 "sell"), 그리고 `price`(가격)와 연결됩니다. 주문은 취소되지 않는 한 **활성(active)** 상태로 간주됩니다.

`OrderManagementSystem` 클래스를 구현하세요:

*   `OrderManagementSystem()`: 주문 관리 시스템을 초기화합니다.
*   `void addOrder(int orderId, string orderType, int price)`: 주어진 속성을 가진 새로운 활성 주문을 추가합니다. `orderId`는 고유함이 보장됩니다.
*   `void modifyOrder(int orderId, int newPrice)`: 기존 주문의 가격을 수정합니다. 해당 주문은 존재하며 활성 상태임이 보장됩니다.
*   `void cancelOrder(int orderId)`: 기존 주문을 취소합니다. 해당 주문은 존재하며 활성 상태임이 보장됩니다.
*   `vector<int> getOrdersAtPrice(string orderType, int price)`: 주어진 `orderType`과 `price`에 일치하는 모든 활성 주문의 `orderId` 목록을 반환합니다. 일치하는 주문이 없으면 빈 리스트를 반환합니다.
    *   **참고:** 반환되는 `orderId`의 순서는 상관없습니다.

**예시 1:**
*   **입력:**
    `["OrderManagementSystem", "addOrder", "addOrder", "addOrder", "getOrdersAtPrice", "modifyOrder", "modifyOrder", "getOrdersAtPrice", "cancelOrder", "cancelOrder", "getOrdersAtPrice"]`
    `[[], [1, "buy", 1], [2, "buy", 1], [3, "sell", 2], ["buy", 1], [1, 3], [2, 1], ["buy", 1], [3], [2], ["buy", 1]]`
*   **출력:**
    `[null, null, null, null, [2, 1], null, null, [2], null, null, []]`
*   **설명:**
    1.  `addOrder(1, "buy", 1)`: ID 1인 매수(buy) 주문을 가격 1로 추가.
    2.  `addOrder(2, "buy", 1)`: ID 2인 매수 주문을 가격 1로 추가.
    3.  `addOrder(3, "sell", 2)`: ID 3인 매도(sell) 주문을 가격 2로 추가.
    4.  `getOrdersAtPrice("buy", 1)`: 가격 1인 활성 매수 주문은 ID 1과 2이므로 `[2, 1]` 반환.
    5.  `modifyOrder(1, 3)`: 주문 1의 가격을 3으로 수정.
    6.  `modifyOrder(2, 1)`: 주문 2의 가격을 1로 수정(기존과 동일).
    7.  `getOrdersAtPrice("buy", 1)`: 가격 1인 활성 매수 주문은 이제 ID 2뿐이므로 `[2]` 반환.
    8.  `cancelOrder(3)`: 주문 3 취소.
    9.  `cancelOrder(2)`: 주문 2 취소.
    10. `getOrdersAtPrice("buy", 1)`: 남은 활성 매수 주문이 없으므로 `[]` 반환.

**제약 사항:**
*   `1 <= orderId <= 2000`
*   `orderId`는 모든 주문에 대해 고유합니다.
*   `orderType`은 "buy" 또는 "sell" 중 하나입니다.
*   `1 <= price <= 10^9`
*   `addOrder`, `modifyOrder`, `cancelOrder`, `getOrdersAtPrice`의 전체 호출 횟수는 **2000회**를 초과하지 않습니다.
*   `modifyOrder`와 `cancelOrder` 호출 시, 해당 `orderId`는 반드시 존재하며 활성 상태임이 보장됩니다.

---

**힌트:**
특정 가격에 해당하는 주문들을 빠르게 찾으려면 어떤 자료구조를 사용하는 것이 좋을까요? 또한, `orderId`를 통해 주문의 정보를 즉시 조회하거나 수정해야 하므로 **해시 맵(Hash Map)**과 **가격별 그룹화**를 조합해서 생각해 보세요.*/
