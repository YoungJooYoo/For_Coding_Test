class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root) return nullptr;

        Node* current = root;
        while (current != nullptr) {
            Node* dummyHead = new Node(0);
            Node* temp = dummyHead;
            
            // 현재 레벨의 모든 노드를 순회
            while (current != nullptr) {
                if (current->left != nullptr) {
                    temp->next = current->left;
                    temp = temp->next;
                }
                if (current->right != nullptr) {
                    temp->next = current->right;
                    temp = temp->next;
                }
                current = current->next;
            }
            
            // 다음 레벨로 이동
            current = dummyHead->next;
            delete dummyHead; // 메모리 누수 방지
        }

        return root;
    }
};

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
이 코드는 주어진 이진 트리의 모든 노드를 같은 레벨 내에서 오른쪽으로 연결하는 문제를 해결하기 위해 작성되었습니다. 여기서 중요한 부분은, 각 레벨의 노드들을 순회하면서 다음 레벨의 노드들을 찾아내고, 이들을 서로 연결하는 것입니다. 이 과정에서 `dummyHead`와 `temp` 두 개의 포인터를 사용하는 이유를 설명해 드리겠습니다.

### `dummyHead`와 `temp`의 역할

- **`dummyHead` 노드**: 이는 현재 처리하고 있는 레벨의 노드들을 연결하기 위한 임시 시작 노드입니다. `dummyHead`는 실제 트리의 일부가 아니라, 각 레벨의 첫 번째 노드를 찾기 위해 사용되는 가상의 노드입니다. 즉, 각 레벨의 첫 번째 실제 노드를 `dummyHead`의 `next` 포인터가 가리키게 됩니다.

- **`temp` 포인터**: 이 포인터는 현재 레벨의 노드들을 순회하며, 다음 레벨의 노드들을 `dummyHead`에 연결하는 역할을 합니다. `temp`는 `dummyHead`에서 시작하여, 현재 레벨의 각 노드의 자식들(`left`, `right`)을 차례로 `next` 포인터를 사용해 연결합니다. 이렇게 함으로써, 다음 레벨의 모든 노드들이 서로 연결됩니다.

### 코드의 작동 방식

1. 각 레벨의 시작에서 `dummyHead` 노드를 새로 생성하고, `temp`를 `dummyHead`에 할당합니다. 이 때, `dummyHead`는 그 레벨의 첫 번째 실제 노드를 가리키게 될 `next` 포인터를 가지고 시작합니다.

2. 현재 레벨의 모든 노드(`current` 포인터로 표시)를 순회하면서, 각 노드의 `left`와 `right` 자식이 있을 경우, 이들을 `temp->next`에 차례로 연결합니다. 그리고 `temp`를 계속해서 다음 노드로 옮겨갑니다.

3. 모든 자식 노드들이 연결된 후, `dummyHead->next`는 다음 레벨의 첫 번째 노드를 가리키게 되며, `current` 포인터를 이 위치로 옮겨 다음 레벨의 노드들을 처리합니다.

### 요약

따라서, `dummyHead`는 각 레벨을 처리하기 위한 시작점으로 사용되며, 실제 노드들 사이에 연결을 쉽게 만들기 위한 임시 노드 역할을 합니다. 이 방법을 사용함으로써, 추가적인 데이터 구조 없이도 트리의 각 레벨에 있는 노드들을 효과적으로 연결할 수 있습니다.
*/
