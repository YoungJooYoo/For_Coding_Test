class Solution 
{
public:
    Node* flipBinaryTree(Node* root, Node* leaf) 
    {
        flipBinaryTreeHelper(leaf);
        return leaf;
    }

private:
    void flipBinaryTreeHelper(Node* current, bool isLeftChild = true) 
    {
        if (current == nullptr) 
        {
            return;
        }

        // 부모 노드가 nullptr인 경우, 즉 현재 노드가 루트 노드가 될 때
        if (current->parent == nullptr) 
        {
            if (isLeftChild == true) 
            {
                swap(current->parent, current->left);
            } 
            else // right
            {
                swap(current->parent, current->right);
            }

            return;
        }

        // 다음 노드가 왼쪽 자식인지 확인
        const bool nextIsLeftChild = (current->parent->left == current) ? true : false;

        // 현재 노드와 부모 노드 간의 링크를 변경
        if (isLeftChild == true) 
        {
            swap(current->parent, current->left);
        } 
        else 
        {
            swap(current->parent, current->right);
            swap(current->left, current->right);
        }

        // 재귀 호출을 통해 트리의 나머지 부분 조정
        flipBinaryTreeHelper(current->left, nextIsLeftChild);
    }
};

// https://leetcode.com/problems/change-the-root-of-a-binary-tree/description/

/*


**1666. 이진 트리의 루트 변경**  
난이도: 중간

주제: 트리, 재귀, 시뮬레이션

---

이진 트리의 루트 노드와 하나의 리프(leaf) 노드가 주어집니다. 리프가 새로운 루트가 되도록 트리를 재구성하세요.

트리를 재구성하기 위해서는, 리프에서 루트까지의 경로에 있는 각 노드 `cur`에 대해 다음 단계들을 수행할 수 있습니다(루트는 제외):

1. 만약 `cur`에 왼쪽 자식이 있다면, 그 자식은 `cur`의 오른쪽 자식이 됩니다.
2. `cur`의 원래 부모는 `cur`의 왼쪽 자식이 됩니다. 이 과정에서 원래 부모의 `cur`에 대한 포인터는 `null`이 되어, 부모는 최대 한 개의 자식만 가지게 됩니다.

재구성된 트리의 새로운 루트를 반환하세요.

**참고**: 재구성 후 `Node.parent` 포인터를 정확하게 설정하지 않으면 "잘못된 답"을 받을 수 있으니 주의하세요.

---

### 예제 1:

입력: 
```
root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 7
```
출력: 
```
[7,2,null,5,4,3,6,null,null,null,1,null,null,0,8]
```
설명: 리프 노드 7이 새로운 루트가 된 트리입니다.

### 예제 2:

입력: 
```
root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 0
```
출력: 
```
[0,1,null,3,8,5,null,null,null,6,2,null,null,7,4]
```
설명: 리프 노드 0이 새로운 루트가 된 트리입니다.

---

### 제약 사항:

- 트리의 노드 수는 `[2, 100]` 범위에 있습니다.
- `-10^9 <= Node.val <= 10^9`
- 모든 `Node.val`은 고유합니다.
- `leaf` 노드는 트리에 반드시 존재합니다.

*/
