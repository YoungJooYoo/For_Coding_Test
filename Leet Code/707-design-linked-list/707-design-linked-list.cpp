class Node {
  public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    size_t size;
    
    MyLinkedList(): head(nullptr), size(0) {}
    
     ~MyLinkedList() {
        Node *p = head;
        while (head != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
    }

    int get(int index) {
        if(index < 0 || index >= size) {
            return -1;
        }
        Node* current=head;
        
        for(size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);       
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size ) {
            return;
        }
        
        Node* current= head;
        Node* new_node = new Node(val);
        
        if (index == 0) {
            new_node->next = current;
            head = new_node;
        }
        else {
            for(size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
        size++;
    }
   
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) {
            return;
        }
        
        if (index == 0) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;            
        }
        else {
            Node* current = head;
            for(size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* nextNode = current->next->next;
            delete current->next;
            current->next = nextNode;
        }
        size--;
    }
};
