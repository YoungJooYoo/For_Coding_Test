class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) { // 시작점이 p이거나 혹은 q라면 당연히 root가 답 혹은 탐색 중간하다 발견하면
            return root;
        }
        
        TreeNode* left_node = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_node = lowestCommonAncestor(root->right, p, q);
        
        if (left_node != nullptr && right_node != nullptr) { // 탐색한 후 양쪽이 둘다 nullptr로 안오면, 그 root가 답이다
            return root;
        }
        else if (left_node == nullptr && right_node == nullptr) {
            return nullptr;
        }
        else if (left_node != nullptr) {
            return left_node;
        }
        else { // 조건 -> if (right_node != nullptr) 
            return right_node;
        }
    }
};

/*
풀이법 :
코드를 따라가면 결국 여기서 답을 반환한다.


1. Example 1처럼  노드5,  노드,1의 root는 3이다
이 경우에는 재귀시 양쪽의 right_node와 left_node가 p,q이므로 p,q를 반환해 nullptr이 아닌 상황이다.
그 경우에는 root를 반환
if (left_node != nullptr && right_node != nullptr)


2. 높이가 차이 나는 경우.
if (root == p || root == q) 여기서 먼저 위에 있는 것이 답이 된다.
둘줄 한쪽이 어떠한 p,q 노드를 반환하면 재귀로 타고 올라가다
위의 조건문에 p,q인경우 root를 반환, 즉 아래쪽에 p,q가 감지되면
위쪽의 p,q까지 도달시 위의 조건문으로 root를 반환

3. 높이도 차이나고 left, right로  pq가 퍼진경우
1번 사항처럼 결국
if (left_node != nullptr && right_node != nullptr) 여기서 답을 리턴한다.
*/