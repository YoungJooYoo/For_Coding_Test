class FindElements 
{
public:
    FindElements(TreeNode* root) 
    {
        recoverTree(root, 0);
    }
    
    bool find(int const target) const
    {
        if (mNums.find(target) != mNums.end()) // 해시셋에서 검색
        {
            return true;
        } 
        
        return false;
    }
private:
    void recoverTree(TreeNode* root, const int val)
    {
        if (root == nullptr)
        {
            return;
        }

        root->val = val;
        mNums.insert(val);
        recoverTree(root->left, (2 * val) + 1);
        recoverTree(root->right, (2 * val) + 2);
    }

private:
    unordered_set<int> mNums;
};

// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

 /*
 1261. 오염된 이진 트리에서 요소 찾기
중간 난이도

주제

기업

📄 문제 설명
다음 규칙을 따르는 이진 트리가 주어집니다:

root.val == 0
만약 treeNode.val == x이고 treeNode.left가 null이 아니면, treeNode.left.val == 2 * x + 1
만약 treeNode.val == x이고 treeNode.right가 null이 아니면, treeNode.right.val == 2 * x + 2
이제 이 이진 트리는 오염되었는데, 이는 모든 treeNode.val이 -1로 변경되었음을 의미합니다.

FindElements 클래스를 구현하세요:

FindElements(TreeNode* root): 오염된 이진 트리를 초기화하고 복구합니다.
bool find(int target): 복구된 이진 트리에 target 값이 존재하면 true를, 그렇지 않으면 false를 반환합니다.
💡 예제 1:
lua
코드 복사
입력:
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]

출력:
[null,false,true]
설명:

cpp
코드 복사
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // false 반환
findElements.find(2); // true 반환
💡 예제 2:
lua
코드 복사
입력:
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]

출력:
[null,true,true,false]
설명:

cpp
코드 복사
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // true 반환
findElements.find(3); // true 반환
findElements.find(5); // false 반환
💡 예제 3:
lua
코드 복사
입력:
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]

출력:
[null,true,false,false,true]
설명:

cpp
코드 복사
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // true 반환
findElements.find(3); // false 반환
findElements.find(4); // false 반환
findElements.find(5); // true 반환
📌 제약 사항:
TreeNode.val == -1
이진 트리의 높이는 20 이하입니다.
노드의 총 개수는 [1, 10^4] 사이입니다.
find()의 총 호출 횟수는 [1, 10^4] 사이입니다.
0 <= target <= 10^6

 */
