class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        Node* a = p;
        Node* b = q;
        
        while(a != b) {
            a = (a == nullptr) ? q : a->parent; // p or q 둘다 됨
            b = (b == nullptr) ? p : b->parent; // p or q둘다됨   //  q, p순서가 더 빠르다.
        }

        return b; // a or b 둘다 됨
    }
};

/*

풀이법 :
이것은 LinkedList의 Intersection의 변형일 뿐입니다!
a b 위치가 스왑되면서 두 노드간의 간격이 급격하게 줄어들면서
탐색 시간이 줄어든다.
a, b 간격이 줄어들면서 결국 만나게 된다.

만약 같은 높이라면 동시에 만나는 지점이 생긴다.

*/