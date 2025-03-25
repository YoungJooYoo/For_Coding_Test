class Solution 
{
public:
    string kthLuckyNumber(const int k) const 
    {
        assert(k >= MIN_K && k <= MAX_K);
    
        int d = 1;  // d: k번째 행운의 숫자가 d자리임을 찾기 위한 변수
        while (((1LL << (d + 1)) - 2) < k)  // 누적 개수: 2^(d+1) - 2
        {
            ++d;
        }
        
        const int prevCount = (1 << d) - 2;   // 누적 개수 이전까지의 행운의 숫자 개수: (1 << d) - 2
        int indexInGroup = k - prevCount - 1; // d자리 행운의 숫자들 중, k번째 숫자의 0-indexed 위치 계산
        string binaryStr(d, '0'); // d자리 이진수 문자열로 변환 (왼쪽 채우기를 통해 정확히 d자리로 만듦)
        string luckyNumber; // 이진수 문자열에서 '0'은 '4'로, '1'은 '7'로 치환
        for (int i = d - 1; i >= 0; --i) 
        {
            binaryStr[i] = (indexInGroup & 1) ? '1' : '0';
            indexInGroup >>= 1;
        }

        for (const char ch : binaryStr) 
        {
            luckyNumber.push_back(ch == '0' ? '4' : '7');
        }
        
        return luckyNumber;
    }
    
private:
    enum {
        MIN_K = 1,
        MAX_K = 1000000000
    };
};

// https://leetcode.com/problems/find-the-k-th-lucky-number/description/

/*

**2802. K번째 행운의 숫자 찾기**

**난이도:** 중간

**문제 설명:**  
행운의 숫자란 오직 4와 7로만 구성된 숫자를 의미합니다.  
정수 **k**가 주어질 때, k번째 행운의 숫자를 문자열 형태로 반환하세요.

---

**예제 1:**

- **입력:** k = 4  
- **출력:** "47"  
- **설명:**  
  첫 번째 행운의 숫자는 4, 두 번째는 7, 세 번째는 44, 네 번째는 47입니다.

---

**예제 2:**

- **입력:** k = 10  
- **출력:** "477"  
- **설명:**  
  증가하는 순서로 정렬된 행운의 숫자는 다음과 같습니다:  
  4, 7, 44, 47, 74, 77, 444, 447, 474, 477.  
  따라서 10번째 행운의 숫자는 477입니다.

---

**예제 3:**

- **입력:** k = 1000  
- **출력:** "777747447"  
- **설명:**  
  1000번째 행운의 숫자는 777747447임을 보일 수 있습니다.

---

**제약 조건:**

- 1 <= k <= 10^9

---

**힌트:**

1. 정확히 n자리의 행운의 숫자 개수는 2ⁿ개입니다.
2. k번째 행운의 숫자가 몇 자리인지 구할 수 있습니다.
3. k번째 행운의 숫자가 c자리임을 안다고 가정할 때, c자리 행운의 숫자 중 k번째 숫자보다 앞에 몇 개의 숫자가 있는지 계산할 수 있습니다.
4. 이전 힌트에서 구한 숫자를 이진수로 표현한 후, 길이가 c가 되도록 앞에 0을 채워 넣습니다.
5. 이진수에서 0과 1을 각각 4와 7로 대체하면 원하는 행운의 숫자를 얻을 수 있습니다.

---
*/
