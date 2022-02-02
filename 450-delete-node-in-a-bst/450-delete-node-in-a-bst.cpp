class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == NULL) {
            return NULL;
        }
        
        if (root->val == key) { // key를 가진 노드를 찾은 경우
            if (root->left == NULL)  {
                return root->right;
            }
            if (root->right == NULL) {
                return root->left;
            }
            /* 이 구간은, 일단 key value를 가진 노드를 찾으면, 
                그 노드의 오른쪽 val 값이  답이니 일단 temp에 그 값을 넣는다. */
            if (root->right != NULL && root->left != NULL) {
                TreeNode* temp = root->right; // 찾아야하는 값이 key보다 큰 최소값이다. 결국 오른쪽 노드의 value이다.
                while (temp->left != NULL) { // key를 가진 node의 왼뽁주터 탐색, 왼쪽에 가장 작은 value가 있으므로
                    temp = temp->left; // 당장 right노드가 없다면 왼쪽노드 끝까지 탐색, 마지막 노드의 오른쪽 값이 value 
                }
                root->val = temp->val; // key를 가진 node에, 찾아낸 key node->val보다 크지만 최소값을 넣는다.
                root->right = deleteNode(root->right, root->val);
            }
        }
        else { // key를 찾지 못한경우 계속 탐색
            if (root->val > key)  { // 왼쪽을 탐색하는 경우
                root->left = deleteNode(root->left, key);
            }
            else { // 오른쪽을 탐색하는 경우
                root->right = deleteNode(root->right, key);
            }
        }
        
        return root;
    }
};