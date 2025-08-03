
class Solution {
public:
    int findBottomLeftValue(const TreeNode* const root) 
    {
        assert(root != nullptr);
        
        searchBottomLeftRecursive(root, 0);

        return (mMaxDepth == 0) ? root->val : mResult;
    }

private:
    void searchBottomLeftRecursive(const TreeNode* const root, const int depth)
    {
        if (root == nullptr)
        {
            return;
        }

        assert(0 <= depth <= MAX_NODE_COUNT - 1);
        assert(MIN_NODE_VALUE <= root->val && root->val <= MAX_NODE_VALUE);
        if (depth > mMaxDepth)
        {
            mMaxDepth = depth;
            mResult = root->val;
        }

        searchBottomLeftRecursive(root->left, depth + 1);
        searchBottomLeftRecursive(root->right, depth + 1);
    }

private:
    int mResult = 0;
    int mMaxDepth = 0;

    enum
    {
        MIN_NODE_COUNT = 1,
        MAX_NODE_COUNT = 10000,
        MIN_NODE_VALUE = -2147483648, // -(2^31)
        MAX_NODE_VALUE = 2147483647   // 2^31-1
    };
};

// https://leetcode.com/problems/find-bottom-left-tree-value/description/

/*


---

## 513. 이진 트리의 가장 왼쪽 아래 값 찾기

### 문제 설명

이진 트리의 **루트 노드 root**가 주어질 때,
**트리의 마지막 행(가장 아래 레벨)의 가장 왼쪽 값**을 찾아 반환하세요.

---

### 예시

#### 예시 1

```
입력: root = [2,1,3]
출력: 1
```

#### 예시 2

```
입력: root = [1,2,3,4,null,5,6,null,null,7]
출력: 7
```

---

### 제약 사항

* 트리의 노드 개수는 1 이상 10,000 이하입니다.
* 각 노드의 값은 -2,147,483,648 이상 2,147,483,647 이하입니다.

---


*/
