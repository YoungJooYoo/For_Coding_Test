class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        if (root == nullptr) {
            return result;
        }  
        
        queue<TreeNode*> tree_list; // bfs 사용할 큐
        bool direction = false; // true -> right to left , false -> left to right
        tree_list.push(root);
        vector<int> temp;
        
        while(tree_list.empty() == false) {
            size_t list_size = tree_list.size();
            cout << list_size << endl;
            temp; // 각 깊이마다 탐색한 값들을 저장할 배열.
            while (list_size > 0) {
                list_size--;
                TreeNode* front = tree_list.front();
                tree_list.pop();
                // root로 부터 , 그 아래에 있는 깊이의 노드들을 전부 bfs 탐색 큐애 넣는다.
                if (front->left != nullptr) {
                    tree_list.push(front->left);
                }
                if (front->right != nullptr) {
                    tree_list.push(front->right);
                }
                temp.push_back(front->val);
            }
            
            if (direction == true) {
                reverse(temp.begin(), temp.end());
            }
            result.push_back(temp);
            temp.clear();
            direction = !direction;
        }
        
        return result;
    }
};


/*

풀이 해설 :
트리를 일반적은 BFS 탐색 한다.
중간에 flag를 두어서, 방향을 좌우 바꾼다.
탐색은 그대로 하되, 탐색된 결과를 reverse 함수로 뒤집어서 저장하면서
탐색하는 방식

*/

