class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) 
    {
        if (head == nullptr) {
            return;    
        }
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};