class Solution 
{
public:
    bool search(vector<int>& nums, const int target) 
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        assert(MIN_VALUE <= target && target <= MAX_VALUE);

        /* # easy solution # 
            sort(nums.begin(), nums.end());
            if (find(nums.begin(), nums.end(), target) != nums.end()) return true;
            else return false;
        */

        return binarySearch(nums, target);
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 5000,
        MIN_VALUE = -10000,
        MAX_VALUE = 10000
    };

    bool binarySearch(vector<int>& nums, const int target) 
    {
        int left = 0; 
        int right = nums.size() - 1;

        assert(MIN_VALUE <= nums[left] && nums[left] <= MAX_VALUE);
        assert(MIN_VALUE <= nums[right] && nums[right] <= MAX_VALUE);

        while (left <= right) 
        {
            const int mid = left + (right - left) / 2;

            if (nums[mid] == target) return true; // ✅ 찾으면 true 반환
            else if (nums[left] == nums[mid] && nums[mid] == nums[right]) // ✅ 중복 제거: nums[left] == nums[mid] == nums[right] 경우
            {
                ++left;
                --right;
            }
           else if (nums[left] <= nums[mid])  // ✅ 왼쪽 절반이 정렬된 경우
            {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1; // 🔹 왼쪽에서 탐색
                else left = mid + 1;  // 🔹 오른쪽에서 탐색
            } 
            else // ✅ 오른쪽 절반이 정렬된 경우
            {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1; // 🔹 오른쪽에서 탐색
                else right = mid - 1; // 🔹 왼쪽에서 탐색
            }
        }

        return false;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

/*

### **81. 회전된 정렬 배열에서 값 찾기 II (Search in Rotated Sorted Array II)**  
**난이도: 중간 (Medium)**  

---

### **📌 문제 설명**
주어진 정수 배열 `nums`는 **비내림차순(오름차순 또는 같은 값 포함)으로 정렬**되어 있습니다.  
하지만 이 배열은 **알 수 없는 피벗 인덱스 `k`에서 회전(rotated)** 되어 있습니다.  
즉, 배열이 다음과 같은 형태가 됩니다.  
```plaintext
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
```
(여기서 `0 <= k < nums.length` 이며, `0`부터 시작하는 인덱스 기준)

예를 들어,  
```plaintext
원본 배열: [0,1,2,4,4,4,5,6,6,7]
피벗 인덱스: 5
회전 후 배열: [4,5,6,6,7,0,1,2,4,4]
```
처럼 바뀔 수 있습니다.

이제, 회전된 배열 `nums`와 정수 `target`이 주어졌을 때,  
`target`이 배열에 존재하면 `true`, 존재하지 않으면 `false`를 반환하는 함수를 작성하세요.

**연산 횟수를 최대한 줄이는 방식으로 구현해야 합니다.**

---

### **📌 예제**
#### **예제 1**
```plaintext
입력: nums = [2,5,6,0,0,1,2], target = 0
출력: true
```

#### **예제 2**
```plaintext
입력: nums = [2,5,6,0,0,1,2], target = 3
출력: false
```

---

### **📌 제약 조건**
- `1 <= nums.length <= 5000` (배열 길이는 최대 5000)
- `-10⁴ <= nums[i] <= 10⁴` (배열 요소의 값 범위)
- 배열 `nums`는 반드시 **어떤 피벗에서 회전된 상태**임이 보장됨.
- `-10⁴ <= target <= 10⁴`

---

### **📌 추가 질문 (Follow-up)**
이 문제는 **"회전된 정렬 배열에서 값 찾기(Search in Rotated Sorted Array)"** 문제와 비슷하지만,  
**배열 `nums`에 중복 값이 포함될 수 있습니다.**  
이 경우 **시간 복잡도에 영향을 줄까요?**  
그렇다면 **왜 영향을 주는지 설명해보세요.**
*/
