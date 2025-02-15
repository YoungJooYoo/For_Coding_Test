class Solution 
{
public:
    int mostExpensiveItem(const int primeOne, const int primeTwo) const
    {
        assert(primeOne > MIN_PRIME && primeOne < MAX_PRIME);
        assert(primeTwo > MIN_PRIME && primeTwo < MAX_PRIME);
        assert(primeOne * primeTwo < MAX_PRODUCT);

        return primeOne * primeTwo - primeOne - primeTwo; 
    }

private:
    enum
    {
        MIN_PRIME   = 1,
        MAX_PRIME   = 10000,
        MAX_PRODUCT = 100000,
    };
};

// https://leetcode.com/problems/most-expensive-item-that-can-not-be-bought/description/

/*

다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

두 개의 서로 다른 소수 **primeOne**과 **primeTwo**가 주어집니다.

앨리스와 밥은 시장을 방문합니다. 이 시장에는 무한히 많은 아이템이 있으며, 모든 양의 정수 x에 대해 가격이 x인 아이템이 존재합니다. 앨리스는 밥에게 선물할 아이템을 구매하고자 합니다. 그녀는 **primeOne**과 **primeTwo**의 동전을 무한히 가지고 있으며, 이 동전들을 조합하여 아이템을 구매할 수 있습니다.  
앨리스는 밥에게 선물할 수 없는 가장 비싼 아이템의 가격이 얼마인지 알고 싶어합니다.

앨리스가 밥에게 선물할 수 없는 가장 비싼 아이템의 가격을 반환하세요.

---

**예제 1:**

- **입력:** primeOne = 2, primeTwo = 5  
- **출력:** 3  
- **설명:**  
  구매할 수 없는 아이템의 가격은 [1, 3]입니다.  
  3보다 큰 가격의 아이템은 동전 2와 5의 조합으로 모두 구매할 수 있음이 증명됩니다.

---

**예제 2:**

- **입력:** primeOne = 5, primeTwo = 7  
- **출력:** 23  
- **설명:**  
  구매할 수 없는 아이템의 가격은 [1, 2, 3, 4, 6, 8, 9, 11, 13, 16, 18, 23]입니다.  
  23보다 큰 가격의 아이템은 모두 구매할 수 있음이 증명됩니다.

---

**제약 조건:**

- 1 < primeOne, primeTwo < 10⁴  
- primeOne, primeTwo는 소수입니다.  
- primeOne * primeTwo < 10⁵


힌트 1
몇 가지 경우를 직접 써보세요. primeOne * primeTwo보다 큰 모든 아이템은 항상 구매할 수 있음을 알 수 있습니다.

힌트 2
만약 비용이 i인 아이템을 구매할 수 있다면, i + primeOne이나 i + primeTwo 가격의 아이템도 구매할 수 있습니다.

힌트 3
동적 프로그래밍을 사용해보세요.

힌트 4
O(1) 시간 복잡도의 해법도 있습니다: Chicken McNugget 정리를 사용하세요.

*/
