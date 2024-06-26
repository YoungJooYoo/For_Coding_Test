class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        bstToGstHelper(root);
        return root;
    }

private:
    void bstToGstHelper(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return;
        } 

        bstToGstHelper(root->right);  
        mSum += root->val; 
        root->val = mSum; 
        bstToGstHelper(root->left);
    }

    int mSum = 0;
};

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/?envType=daily-question&envId=2024-06-25

/*

### 538. 이진 탐색 트리를 더 큰 트리로 변환

**난이도: 중간**

#### 문제 설명

이진 탐색 트리(BST)의 루트가 주어질 때, 이를 더 큰 트리로 변환하세요. 더 큰 트리란, 원래의 BST의 모든 키가 원래 키에 BST에서 그 키보다 큰 모든 키의 합을 더한 값으로 변환된 트리를 의미합니다.

이진 탐색 트리란 다음과 같은 조건을 만족하는 트리입니다:

1. 노드의 왼쪽 서브트리는 해당 노드의 키보다 작은 키만을 포함합니다.
2. 노드의 오른쪽 서브트리는 해당 노드의 키보다 큰 키만을 포함합니다.
3. 왼쪽 및 오른쪽 서브트리도 각각 이진 탐색 트리여야 합니다.

#### 예제

**예제 1**:

```
입력: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
출력: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

**예제 2**:

```
입력: root = [0,null,1]
출력: [1,null,1]
```

#### 제약 조건

- 트리의 노드 수는 [0, 10^4] 범위 내에 있습니다.
- -10^4 <= Node.val <= 10^4
- 트리 내의 모든 값은 유일합니다.
- 주어진 `root`는 유효한 이진 탐색 트리임이 보장됩니다.
*/
