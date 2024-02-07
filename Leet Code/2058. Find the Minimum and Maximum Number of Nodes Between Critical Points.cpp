class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> criticalPoints;
        ListNode* previous = head;
        ListNode* current = head;
        ListNode* next_node = current->next;
        int idx = 0;
        
        // 중요 지점 찾기
        while (current != nullptr && next_node != nullptr) {
            if ((current->val > previous->val && current->val > next_node->val) ||
                (current->val < previous->val && current->val < next_node->val)) {
                criticalPoints.push_back(idx);
            }
            previous = current;
            current = current->next;
            next_node = next_node->next;
            ++idx;
        }
        
        // 중요 지점이 두 개 미만인 경우
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        // 최소 거리 계산 
        for (int i = 1; i < criticalPoints.size(); ++i) {
            const int distance = criticalPoints[i] - criticalPoints[i - 1];
            minDistance = min(minDistance, distance);
        }
        
        return {minDistance, maxDistance};
    }
};

// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
