class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* temp;
        
        if (node == NULL) {
            return;
        }
        
        if (node->left == NULL) { // 노드의 왼쪽이 비었다면, 오른쪽만 탐색
            return flatten(node->right);
        }

        temp = node->left; // 옮겨야할 노드의 왼쪽을 담아낸다.
        
        while (temp->right != nullptr) { // 담아낸 왼쪽 노드의 오른쪽 노드를 계속 탐색한다.
            temp = temp->right; // 좌측노드의 맨 오른쪽 노드까지 오면, 이 오른쪽 노르를, root의 오른쪽 노드에 바로 붙인다
        }
        
        temp->right = node->right; // root->right의 주소를 가져오고, 여기에 아까 위에서 가져온 좌측 노드를 붙일 작업을 한다. 즉, root의 왼쪽의 오른쪽의 끝을, root의 오른쪽 노드위에 붙이고
        node->right = node->left; // 노드의 왼쪽 요소들을, 노드의 오른쪽으로 붙이는 작업 , 레퍼런스 그림 참조 root의 right 끝에 왼쪽 노드의 root를 붙여버린다.
        node->left = NULL; // node 왼쪽을 NULL로 만드는 것

        return flatten(node->right);
    }
};

/*

reference :
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/1207664/C%2B%2B-8-lines-code-recursive-with-diagram

*/