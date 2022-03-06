class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        Node* a = p;
        Node* b = q;
        
        size_t count = 0;
        while(a != b) {
            a = (a == nullptr) ? q : a->parent; // p or q 둘다 됨
            b = (b == nullptr) ? p : b->parent; // p or q둘다됨   //  q, p순서가 더 빠르다.
            count++;
        }
                 
        cout << "count : " << count << endl;
        return b; // a or b 둘다 됨
    }
};

// // 이것은 LinkedList의 Intersection의 변형일 뿐입니다!