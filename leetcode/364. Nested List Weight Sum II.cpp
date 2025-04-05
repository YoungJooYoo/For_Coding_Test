/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution 
{
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) 
    {
        assert (MIN_LENGTH <= nestedList.size() && nestedList.size() <= MAX_LENGTH);

        mMaxDepth = getMaxDepth(nestedList, 1);
        assert(mMaxDepth <= MAX_DEPTH);
        depthSumInverseHelperRecursive(nestedList, 1);

        return mResult;
    }

private:
    int getMaxDepth(const vector<NestedInteger>& nestedList, int currentDepth) const
    {
        int maxDepth = currentDepth;
        
        for (const auto& ni : nestedList) 
        {
           
            if (!ni.isInteger() == true) 
            {
                const int innerDepth = getMaxDepth(ni.getList(), currentDepth + 1);
                maxDepth = std::max(maxDepth, innerDepth);
            }
        }
        
        return maxDepth;
    }


    void depthSumInverseHelperRecursive(const vector<NestedInteger>& nestedList, const int currentDepth)
    {
        for (const auto& ni : nestedList) 
        {
            if (ni.isInteger() == true) 
            {
                const int value = ni.getInteger();
                assert(MIN_RANGE <= value && value <= MAX_RANGE);
                mResult += value * (mMaxDepth - currentDepth + 1);
            } 
            else 
            {
                depthSumInverseHelperRecursive(ni.getList(), currentDepth + 1);
            }
        }
    }

private:
    int mMaxDepth = 0;
    int mResult = 0;

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 50,
        MIN_RANGE = -100,
        MAX_RANGE = 100,
        MAX_DEPTH = 50,
    };
};

// https://leetcode.com/problems/nested-list-weight-sum-ii/description/

/*


/**
 * // 중첩 리스트 생성을 위한 인터페이스입니다.
 * // 이 인터페이스는 직접 구현하거나 구현 세부 사항을 추측해서는 안 됩니다.
 * class NestedInteger {
 *   public:
 *     // 생성자는 빈 중첩 리스트를 초기화합니다.
 *     NestedInteger();
 *
 *     // 생성자는 단일 정수를 초기화합니다.
 *     NestedInteger(int value);
 *
 *     // 이 NestedInteger가 중첩 리스트가 아니라 단일 정수를 보유하고 있다면 true를 반환합니다.
 *     bool isInteger() const;
 *
 *     // 이 NestedInteger가 단일 정수를 보유하고 있다면 해당 정수를 반환합니다.
 *     // 이 NestedInteger가 중첩 리스트를 보유하고 있다면 결과는 정의되지 않습니다.
 *     int getInteger() const;
 *
 *     // 이 NestedInteger가 단일 정수를 보유하도록 설정합니다.
 *     void setInteger(int value);
 *
 *     // 이 NestedInteger를 중첩 리스트로 설정하고, 중첩 정수를 추가합니다.
 *     void add(const NestedInteger &ni);
 *
 *     // 이 NestedInteger가 중첩 리스트를 보유하고 있다면, 해당 중첩 리스트를 반환합니다.
 *     // 이 NestedInteger가 단일 정수를 보유하고 있다면 결과는 정의되지 않습니다.
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
**문제 364. Nested List Weight Sum II**  
*난이도: Medium*

정수로 구성된 중첩 리스트 **nestedList**가 주어집니다. 각 요소는 정수이거나, 그 요소들이 정수 또는 다른 리스트일 수 있는 리스트입니다.

정수의 **깊이(depth)**란 해당 정수가 포함되어 있는 리스트의 수를 의미합니다. 예를 들어, 중첩 리스트 `[1, [2,2], [[3],2], 1]`에서 각 정수의 깊이는 해당 정수가 포함된 리스트의 개수로 결정됩니다. **maxDepth**는 중첩 리스트 내의 모든 정수 중 가장 큰 깊이입니다.

정수의 **가중치(weight)**는 `maxDepth - (정수의 깊이) + 1`로 정의됩니다.

**nestedList**에 있는 각 정수에 대해, 해당 정수와 그 가중치를 곱한 값을 모두 합한 결과를 반환하세요.

---

**예제 1:**

- 입력: `nestedList = [[1,1],2,[1,1]]`
- 출력: `8`
- 설명: 네 개의 1은 가중치가 1이고, 하나의 2는 가중치가 2입니다.  
  계산: `1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8`

**예제 2:**

- 입력: `nestedList = [1,[4,[6]]]`
- 출력: `17`
- 설명: 깊이가 3인 1, 깊이가 2인 4, 깊이가 1인 6이 있습니다.  
  계산: `1*3 + 4*2 + 6*1 = 17`

---

**제약 조건:**

- `1 <= nestedList.length <= 50`
- 중첩 리스트에 포함된 정수의 값은 `[-100, 100]` 범위에 있습니다.
- 모든 정수의 최대 깊이는 50 이하입니다.
- 빈 리스트는 주어지지 않습니다.
*/
