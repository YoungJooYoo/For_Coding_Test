class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == NULL) {
            return NULL;
        }
        
        if (root->val == key) { // key를 가진 노드를 찾을때
            if(root->left == NULL)  return root->right;
            if(root->right == NULL) return root->left;
            if(root->right!=NULL && root->left!=NULL){
                TreeNode *temp = root->right;
                while(temp->left!=NULL) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right,root->val);
                
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