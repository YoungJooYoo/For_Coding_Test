class Solution 
{
public:
	vector<int> toArray(Node* const head)
    {
        vector<int> nums;

        Node* node = head;
        while  (node != nullptr)
        {
            nums.push_back(node->val);
            node = node->next;
        }

        return nums;
    }
};

// https://leetcode.com/problems/convert-doubly-linked-list-to-array-i/description/
