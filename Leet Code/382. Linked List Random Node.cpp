class Solution {
public:
    Solution(ListNode* head) 
    {
        while (head != nullptr) {
            mNodes.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() 
    {
        const size_t random_idx = rand() % mNodes.size();
        return mNodes[random_idx]->val;
    }

private:
    vector<ListNode*> mNodes;
};

// https://leetcode.com/problems/linked-list-random-node/description/
