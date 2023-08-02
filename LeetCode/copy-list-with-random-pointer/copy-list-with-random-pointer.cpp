class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        Node* temp;
        Node* ans;
        Node* helper;
        
        // STEP 1: PASS 1
        // Creating a copy (except random pointer) of each old node and insert it next to the old node it's copied from.
        // That is, it will create new alternative nodes which are a copy (except random pointer) of its previous node.
        while(node != nullptr) {
            temp = node->next;
            node->next = new Node(node->val);
            node->next->next = temp;
            node = temp;
        }
        
        // STEP 2: PASS 2
        // Now copy the random pointer (if exists) of the old nodes to their copy new nodes.
        node = head;
        while (node != nullptr) {
            if(node->random != nullptr) {
                node->next->random = node->random->next;
            }
            node = node->next->next; // go to next old node, node->next is "a copied node"
        }
        
        //STEP 3: PASS 3
        // Copy the alternative nodes into "ans" link list using the "helper" pointer along with restoring the old link list.
        ans = new Node(0); // first node is a dummy node
        helper = ans;
    
        while(head != nullptr){
            // Copy the alternate added nodes from the old linklist
            helper->next = head->next;
            helper = helper->next;
            
            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next = head->next->next;
            head = head->next; // go to next alternate node   
        }
        
        return ans->next; // Since first node is a dummy node
    }
};

/*
풀이법 : 총 3단계에 나누어서 복사

1. deep copy를 만들기, deep copy를 기존에 노스 사이 사이에 넣는다. 
   ex) 원본 -> 원본 -> 원본 -> 원본 -> NULL   ==>   원본 -> 카피본 -> 원본 -> 카피본 -> 원본 -> 카피본 -> 원본 -> 카피본 -> NULL
2. random 포인터 복사하기
3. 카피본 -> 카피본 -> 카피본 -> 카피본 -> NULL 을 만드는 작업

참조 URL : https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)

*/
