class Solution 
{
public:
    bool isZeroArray(const vector<int> &nums, const vector<vector<int>> &queries) const
    {
        assert(nums.size() >= MIN_NUMS_SIZE && nums.size() <= MAX_NUMS_SIZE);
        assert(queries.size() >= MIN_QUERIES_SIZE && queries.size() <= MAX_QUERIES_SIZE);
        
        const size_t arraySize = nums.size();
        vector<int> diff(arraySize + 1, 0);

        for (const vector<int> &query : queries)
        {
            assert(query.size() == QUERY_ELEMENT_COUNT);
            assert(query[0] >= 0 && query[0] < static_cast<int>(arraySize));
            assert(query[1] >= 0 && query[1] < static_cast<int>(arraySize));
            assert(query[0] <= query[1]);

            const int left = query[0];
            const int right = query[1];
            ++diff[left];

            if (right + 1 < static_cast<int>(arraySize))
            {
                --diff[right + 1];
            }
        }
        
        vector<int> queryCount(arraySize, 0);
        queryCount[0] = diff[0];
        for (size_t i = 1; i < arraySize; i++)
        {
            queryCount[i] = queryCount[i - 1] + diff[i];
        }
        
        for (size_t i = 0; i < arraySize; i++)
        {
            assert(nums[i] >= MIN_NUM_VALUE && nums[i] <= MAX_NUM_VALUE);
            if (queryCount[i] < nums[i])
            {
                return false;
            }
        }
        
        return true;
    }

private:
    enum
    {
        MIN_NUMS_SIZE      = 1,
        MAX_NUMS_SIZE      = 100000,  // 10^5
        MIN_NUM_VALUE      = 0,
        MAX_NUM_VALUE      = 100000,  // 10^5
        MIN_QUERIES_SIZE   = 1,
        MAX_QUERIES_SIZE   = 100000,  // 10^5
        QUERY_ELEMENT_COUNT = 2
    };
};


/*


**3355. 제로 배열 변환 I**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

길이 n인 정수 배열 **nums**와 2차원 배열 **queries**가 주어집니다.  
여기서 **queries[i] = [lᵢ, rᵢ]** 입니다.

각각의 **queries[i]**에 대해 다음을 수행합니다:

- **nums** 배열의 인덱스 범위 **[lᵢ, rᵢ]** 내에서 임의의 인덱스 집합(subset)을 선택합니다.
- 선택된 인덱스들의 값을 1씩 감소시킵니다.

**제로 배열 (Zero Array)** 은 모든 원소가 0인 배열을 의미합니다.

모든 쿼리를 순서대로 처리한 후 **nums**를 제로 배열로 변환시킬 수 있다면 **true**를, 그렇지 않으면 **false**를 반환하세요.

---

**예제 1:**

- **입력:** nums = [1, 0, 1], queries = [[0, 2]]
- **출력:** true
- **설명:**  
  쿼리 0에 대해:  
  인덱스 범위 [0, 2] 내의 인덱스 집합으로 [0, 2]를 선택하고, 해당 인덱스의 값을 1씩 감소시킵니다.  
  그러면 배열은 [0, 0, 0]이 되어 제로 배열이 됩니다.

---

**예제 2:**

- **입력:** nums = [4, 3, 2, 1], queries = [[1, 3], [0, 2]]
- **출력:** false
- **설명:**  
  쿼리 0에 대해:  
  인덱스 범위 [1, 3] 내에서 [1, 2, 3]을 선택하여 값을 1씩 감소시키면, 배열은 [4, 2, 1, 0]이 됩니다.  
  쿼리 1에 대해:  
  인덱스 범위 [0, 2] 내에서 [0, 1, 2]를 선택하여 값을 1씩 감소시키면, 배열은 [3, 1, 0, 0]이 됩니다.  
  최종 배열이 제로 배열이 아니므로 false를 반환합니다.

---

**제약 조건:**

- 1 <= nums.length <= 10⁵  
- 0 <= nums[i] <= 10⁵  
- 1 <= queries.length <= 10⁵  
- queries[i].length == 2  
- 0 <= lᵢ <= rᵢ < nums.length

---

**힌트 1:**  
차분 배열(difference array)과 누적합(prefix sum)을 사용하여 각 인덱스를 0으로 만들 수 있는지 확인할 수 있을지 생각해보세요.
*/

// https://leetcode.com/problems/zero-array-transformation-i/
