class ProductOfNumbers 
{
public:
    ProductOfNumbers() 
    : prefixProducts(1, 1)
    {

    }
    
    void add(const int num) 
    {
        assert(MIN_NUM <= num && num <= MAX_NUM);
        if (num == 0) 
        {
            prefixProducts.clear();
            prefixProducts.push_back(1);
        } 
        else 
        {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(const int k) const 
    {
        assert(MIN_K <= k && k <= MAX_K);
        const int size = prefixProducts.size();
        
        if (size <= k) // 만약 마지막 k개의 숫자 사이에 0이 있었으면 누적 곱이 리셋되어, 배열 크기가 k+1보다 작습니다.
        {
            return 0;
        }
            
        return prefixProducts.back() / prefixProducts[size - k - 1];
    }

private:
    vector<int> prefixProducts;

    enum {
        MIN_NUM = 0,
        MAX_NUM = 100,
        MIN_K = 1,
        MAX_K = 4 * 10000,
    };
};

// https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14

/*

다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**1352. 마지막 K개의 수의 곱**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

정수 스트림을 입력받아, 스트림의 마지막 K개의 정수의 곱을 구하는 알고리즘을 설계하세요.

**ProductOfNumbers 클래스 구현:**

- **ProductOfNumbers()**  
  → 빈 스트림으로 객체를 초기화합니다.
  
- **void add(int num)**  
  → 정수 num을 스트림에 추가합니다.
  
- **int getProduct(int k)**  
  → 현재 리스트에서 마지막 k개의 수의 곱을 반환합니다.  
  → 현재 리스트에는 항상 최소 k개의 숫자가 있다고 가정할 수 있습니다.

테스트 케이스는 언제든 연속된 숫자들의 곱이 32비트 정수 하나에 담길 수 있도록 생성됩니다.

---

**예제:**

```
Input:
["ProductOfNumbers", "add", "add", "add", "add", "add", "getProduct", "getProduct", "getProduct", "add", "getProduct"]
[[], [3], [0], [2], [5], [4], [2], [3], [4], [8], [2]]

Output:
[null, null, null, null, null, null, 20, 40, 0, null, 32]
```

**설명:**

```cpp
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // 스트림: [3]
productOfNumbers.add(0);        // 스트림: [3, 0]
productOfNumbers.add(2);        // 스트림: [3, 0, 2]
productOfNumbers.add(5);        // 스트림: [3, 0, 2, 5]
productOfNumbers.add(4);        // 스트림: [3, 0, 2, 5, 4]
productOfNumbers.getProduct(2); // 마지막 2개의 수의 곱: 5 * 4 = 20, 반환 20
productOfNumbers.getProduct(3); // 마지막 3개의 수의 곱: 2 * 5 * 4 = 40, 반환 40
productOfNumbers.getProduct(4); // 마지막 4개의 수의 곱: 0 * 2 * 5 * 4 = 0, 반환 0
productOfNumbers.add(8);        // 스트림: [3, 0, 2, 5, 4, 8]
productOfNumbers.getProduct(2); // 마지막 2개의 수의 곱: 4 * 8 = 32, 반환 32
```

---

**제약 조건:**

- 0 <= num <= 100  
- 1 <= k <= 4 * 10⁴  
- add와 getProduct 함수는 최대 4 * 10⁴회 호출됩니다.  
- 스트림의 어느 시점에서든, 연속된 숫자들의 곱은 32비트 정수 범위 내에 들어갑니다.

---

**Follow-up:**  
GetProduct와 Add 함수를 O(k) 대신 O(1) 시간 복잡도로 구현할 수 있을까요?

*/

