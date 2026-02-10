class Solution 
{
public:
    TreeNode* balanceBST(const TreeNode* const root) 
    {
        getTreeValueRecursive(root);
        assert(mTreeValues.size() > 0);

        return buildBalancedTree(0, static_cast<int>(mTreeValues.size()) - 1);
    }

private:
    void getTreeValueRecursive(const TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        getTreeValueRecursive(root->left);
        mTreeValues.push_back(root->val);
        getTreeValueRecursive(root->right);
        assert(MIN_VAL <= root->val && root->val <= MAX_VAL);
    }

    TreeNode* buildBalancedTree(const int left, const int right) const
    {
        if (left > right)
        {
            return nullptr;
        }

        const int mid = left + ((right - left) / 2);
        TreeNode* const node = new TreeNode(mTreeValues[mid]);
        assert(node != nullptr);
        node->left = buildBalancedTree(left, mid - 1);
        node->right = buildBalancedTree(mid + 1, right);

        return node;
    }

private:
    vector<int> mTreeValues;

    enum
    {
        MIN_VAL = 1,
        MAX_VAL= 100000
    };
};


/*
https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

# 1382. 이진 탐색 트리 균형 맞추기 (Balance a Binary Search Tree)

이진 탐색 트리(BST)의 루트 노드가 주어집니다.
**같은 노드 값들을 유지하면서, 균형 잡힌 이진 탐색 트리를 반환하세요.**

정답이 여러 개일 수 있다면, **그중 아무거나 반환해도 됩니다.**

---

## 균형 잡힌 이진 탐색 트리(Balanced BST)란?

모든 노드에 대해
**왼쪽 서브트리와 오른쪽 서브트리의 깊이 차이가 1을 초과하지 않는 트리**를 말합니다.

---

## 예시 1

**입력**

```
root = [1, null, 2, null, 3, null, 4, null, null]
```

**출력**

```
[2, 1, 3, null, null, null, 4]
```

**설명**
이 출력만이 유일한 정답은 아닙니다.
예를 들어 아래 트리도 올바른 정답입니다:

```
[3, 1, 4, null, 2]
```

---

## 예시 2

**입력**

```
root = [2, 1, 3]
```

**출력**

```
[2, 1, 3]
```

이미 균형 잡힌 트리이므로 그대로 반환합니다.

---

## 제약 조건

* 트리의 노드 개수는 **1 이상 10,000 이하**
* 각 노드의 값은 **1 이상 100,000 이하**

---



*/
