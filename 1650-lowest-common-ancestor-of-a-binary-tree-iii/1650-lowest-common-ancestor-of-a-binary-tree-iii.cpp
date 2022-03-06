class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        Node* a = p;
        Node* b = q;
        
        size_t count = 0;
        while(a != b) {
            a = (a == nullptr) ? p : a->parent;
            b = (b == nullptr) ? q : b->parent;
        }
                 
        return b; // a or b 둘다 됨
    }
};

// // 이것은 LinkedList의 Intersection의 변형일 뿐입니다!