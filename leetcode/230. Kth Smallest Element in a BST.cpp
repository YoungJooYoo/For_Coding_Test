class Solution
{
public:
    int kthSmallest(const TreeNode* const root, const int k)
    {
        assert(root != nullptr);
        assert(MIN_K <= k && k <= MAX_N);

        mNodeCount = 0;
        dfsRecursive(root);
        assert(mNodeCount >= k); // 트리의 노드 개수가 k 이상인지 확인

        int result = 0;
        int remain = k;

        while (remain-- != 0)
        {
            result = mQueue.top();
            mQueue.pop();
        }

        return result;
    }

private:
    void dfsRecursive(const TreeNode* const node)
    {
        if (node == nullptr)
        {
            return;
        }
        
        assert(MIN_VAL <= node->val && node->val <= MAX_VAL);
        ++mNodeCount;
        mQueue.push(node->val);
        dfsRecursive(node->left);
        dfsRecursive(node->right);
    }

    priority_queue<int, vector<int>, greater<int>> mQueue;
    int mNodeCount = 0;

    enum
    {
        MIN_K = 1,
        MAX_N = 10000,
        MIN_VAL = 0,
        MAX_VAL = 10000
    };
};

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

/*

230. 이진 탐색 트리에서 k번째로 작은 원소
난이도: 중

문제 설명
이진 탐색 트리(BST)의 루트 노드와 정수 k가 주어집니다.
트리 안에 있는 모든 노드 값 중 **k번째로 작은 값(1부터 시작, 1-indexed)**을 반환하세요.

예시
예시 1
makefile
복사
편집
입력: root = [3,1,4,null,2], k = 1
출력: 1
예시 2
csharp
복사
편집
입력: root = [5,3,6,2,4,null,null,1], k = 3
출력: 3
제약사항
트리의 노드 개수는 n입니다.

1 <= k <= n <= 10,000

0 <= Node.val <= 10,000

추가 질문
만약 BST가 자주 수정(삽입/삭제)되면서 k번째 원소를 자주 찾아야 한다면,
어떻게 하면 더 효율적으로 구현할 수 있을까요?
*/
