class Solution 
{
public:
    vector<TreeNode*> splitBST(TreeNode* root, const int target) 
    {
        if (root == nullptr) 
        {
            return {nullptr, nullptr};
        }

        if (root->val <= target) 
        {
            vector<TreeNode*> splitRight = splitBST(root->right, target);
            root->right = splitRight[0];
            return {root, splitRight[1]};
        } 
        else 
        {
            vector<TreeNode*> splitLeft = splitBST(root->left, target);
            root->left = splitLeft[1];
            return {splitLeft[0], root};
        }
    }
};

// https://leetcode.com/problems/split-bst/description/

/*
### 776. 이진 탐색 트리 분할

**난이도: 중간**

#### 문제 설명

이진 탐색 트리(BST)의 루트와 정수 `target`이 주어질 때, 트리를 두 개의 서브트리로 분할하세요. 첫 번째 서브트리는 모든 노드가 `target` 값보다 작거나 같은 노드를 가지고, 두 번째 서브트리는 모든 노드가 `target` 값보다 큰 노드를 가집니다. 트리에는 `target` 값을 가진 노드가 반드시 존재할 필요는 없습니다.

추가적으로, 원래 트리의 대부분의 구조를 유지해야 합니다. 즉, 원래 트리에서 부모 노드 `p`와 자식 노드 `c`가 동일한 서브트리에 속해 있다면, 분할 후에도 노드 `c`는 여전히 부모 노드 `p`를 가져야 합니다.

두 서브트리의 루트를 순서대로 배열에 담아 반환하세요.

#### 예제

**예제 1**:

- 입력: `root = [4,2,6,1,3,5,7]`, `target = 2`
- 출력: `[[2,1],[4,3,6,null,null,5,7]]`

**예제 2**:

- 입력: `root = [1]`, `target = 1`
- 출력: `[[1],[]]`

#### 제약 조건

- 트리의 노드 수는 `[1, 50]` 범위 내에 있습니다.
- `0 <= Node.val, target <= 1000`

---

이 문제는 이진 탐색 트리를 주어진 `target` 값에 따라 두 개의 서브트리로 분할하는 것입니다. 각 서브트리의 루트를 반환해야 하며, 원래 트리의 부모-자식 관계를 최대한 유지해야 합니다.
*/

/*
코드 설명
기저 조건:

현재 노드가 nullptr이면, 빈 서브트리를 반환합니다.
현재 노드 값이 target보다 작거나 같은 경우:

현재 노드의 오른쪽 서브트리를 분할합니다.
분할 결과의 첫 번째 서브트리를 현재 노드의 오른쪽 자식으로 연결합니다.
현재 노드를 포함한 트리와 분할 결과의 두 번째 서브트리를 반환합니다.
현재 노드 값이 target보다 큰 경우:

현재 노드의 왼쪽 서브트리를 분할합니다.
분할 결과의 두 번째 서브트리를 현재 노드의 왼쪽 자식으로 연결합니다.
분할 결과의 첫 번째 서브트리와 현재 노드를 포함한 트리를 반환합니다.
이 접근법은 재귀적으로 트리를 분할하며, BST의 특성을 활용하여 각 노드를 적절히 연결합니다. 이를 통해 원래 트리의 구조를 최대한 유지하면서 트리를 두 개의 서브트리로 분할할 수 있습니다.
*/
