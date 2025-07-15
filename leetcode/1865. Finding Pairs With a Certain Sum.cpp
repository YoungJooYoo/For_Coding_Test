class FindSumPairs
{
public:
    FindSumPairs(const vector<int>& nums1, const vector<int>& nums2)
        : mNums1(nums1)
        , mNums2(nums2)
    {
        assert(MIN_NUMS1_LEN <= nums1.size() && nums1.size() <= MAX_NUMS1_LEN);
        assert(MIN_NUMS2_LEN <= nums2.size() && nums2.size() <= MAX_NUMS2_LEN);
        for (const int num : mNums2)
        {
            assert(MIN_NUMS2 <= num && num <= MAX_NUMS2);
            ++mNums2Count[num];
        }
    }

    void add(const int index, const int val)
    {
        assert(0 <= index && static_cast<size_t>(index) < mNums2.size());
        assert(MIN_VAL <= val && val <= MAX_VAL);

        const int oldValue = mNums2[index];
        const int newValue = oldValue + val;

        --mNums2Count[oldValue];
        mNums2[index] = newValue;
        ++mNums2Count[newValue];
    }

    int count(const int tot) const
    {
        assert(MIN_TOT <= tot && tot <= MAX_TOT);

        int result = 0;
        for (const int x : mNums1)
        {
            assert(MIN_NUMS1 <= x && x <= MAX_NUMS1);
            const int y = tot - x;
            if (mNums2Count.count(y) > 0)
            {
                result += mNums2Count.at(y);
            }
        }
        
        return result;
    }

private:
    vector<int> mNums1;
    vector<int> mNums2;
    unordered_map<int, int> mNums2Count;

    enum
    {
        MIN_NUMS1_LEN = 1,
        MAX_NUMS1_LEN = 1000,
        MIN_NUMS2_LEN = 1,
        MAX_NUMS2_LEN = 100000,
        MIN_NUMS1 = 1,
        MAX_NUMS1 = 1000000000,
        MIN_NUMS2 = 1,
        MAX_NUMS2 = 100000,
        MIN_VAL = 1,
        MAX_VAL = 100000,
        MIN_TOT = 1,
        MAX_TOT = 1000000000
    };
};

// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06

/*

---

## 1865. 특정 합을 가지는 쌍 찾기

**난이도: 중**

---

### 문제 설명

정수 배열 `nums1`과 `nums2`가 주어집니다.
당신은 아래 두 가지 쿼리를 지원하는 **자료구조**를 구현해야 합니다.

1. **add(index, val)**
   `nums2`의 특정 인덱스에 있는 값에 양의 정수 `val`을 더합니다.
   즉, `nums2[index] += val` 연산을 수행합니다.

2. **count(tot)**
   쌍 `(i, j)`에 대해
   `nums1[i] + nums2[j] == tot`를 만족하는 쌍의 개수를 반환합니다.
   (단, 0 <= i < nums1.length, 0 <= j < nums2.length)

---

### 클래스 및 함수 정의

* `FindSumPairs(int[] nums1, int[] nums2)`
  두 정수 배열로 FindSumPairs 객체를 초기화합니다.

* `void add(int index, int val)`
  nums2\[index]에 val을 더합니다.

* `int count(int tot)`
  nums1\[i] + nums2\[j] == tot 인 모든 쌍 (i, j)의 개수를 반환합니다.

---

### 예시

**입력**
\["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
\[\[\[1, 1, 2, 2, 2, 3], \[1, 4, 5, 2, 5, 4]], \[7], \[3, 2], \[8], \[4], \[0, 1], \[1, 1], \[7]]

**출력**
\[null, 8, null, 2, 1, null, null, 11]

**설명**

```
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // 8 반환; 예를 들어 (2,2), (3,2), (4,2), (2,4), (3,4), (4,4)는 2+5, (5,1), (5,5)는 3+4 쌍
findSumPairs.add(3, 2); // 이제 nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // 2 반환; (5,2), (5,4)는 3+5
findSumPairs.count(4);  // 1 반환; (5,0)은 3+1
findSumPairs.add(0, 1); // 이제 nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // 이제 nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // 11 반환; (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4)는 2+5, (5,3), (5,5)는 3+4
```

---

### 제약사항

* 1 <= nums1.length <= 1,000
* 1 <= nums2.length <= 100,000
* 1 <= nums1\[i] <= 1,000,000,000
* 1 <= nums2\[i] <= 100,000
* 0 <= index < nums2.length
* 1 <= val <= 100,000
* 1 <= tot <= 1,000,000,000
* **add와 count 함수 각각 최대 1,000번 호출**

---

#### 힌트

* nums1의 길이가 nums2에 비해 작음
* nums1의 각 원소에 대해, tot - 원소 값을 nums2에서 얼마나 가지는지 세면 됨

---

*/
