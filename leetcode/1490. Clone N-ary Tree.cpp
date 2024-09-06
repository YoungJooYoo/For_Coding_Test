/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// https://leetcode.com/problems/clone-n-ary-tree/description/

class Solution 
{
public:
    Node* cloneTree(const Node* const root) const // root가 const이고, 메서드도 클래스의 상태를 변경하지 않음
    {
        if (root == nullptr) 
        {
            return nullptr;
        }

        return deepCopy(root); 
    }
    
private:
    Node* deepCopy(const Node* const root) const // root가 const이고, 메서드도 클래스의 상태를 변경하지 않음
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        Node* const newNode = new Node(root->val);

        for (const auto& child : root->children) // 자식들을 순회하면서 각각 깊은 복사
        {
            newNode->children.push_back(deepCopy(child));
        }

        return newNode;
    }
};
/*

번역: 1490. N-ary 트리 복제하기
난이도: 중간
주제
회사
힌트
N-ary 트리의 루트가 주어졌을 때, 트리의 깊은 복사본(클론)을 반환하세요.

N-ary 트리의 각 노드는 하나의 값(val, 정수)과 자식 노드의 리스트(List[Node])를 포함합니다.

```java
class Node {
    public int val;
    public List<Node> children;
}
```

N-ary 트리 입력 직렬화는 레벨 순서 탐색으로 표현되며, 각 자식 그룹은 null 값으로 구분됩니다(예제 참조).

예제 1:

입력: root = [1,null,3,2,4,null,5,6]
출력: [1,null,3,2,4,null,5,6]

예제 2:

입력: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
출력: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]

제한 사항:

N-ary 트리의 깊이는 1000 이하입니다.
노드의 총 수는 [0, 10^4] 범위입니다.

추가 질문: 이 솔루션을 그래프 문제에도 적용할 수 있나요?
*/
