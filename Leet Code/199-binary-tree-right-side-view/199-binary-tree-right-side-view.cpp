class Solution {
public:
    void recursion(TreeNode *root, int level)
    {
        if (root == nullptr) {
            return;
        }
        if (result.size() < level) { // 후위순회시 오른쪽만 본다면, 레벨이랑, 배열의 길이랑 연관이 있다.
            result.push_back(root->val);
        }
        
        // 후위순회로 탐색
        recursion(root->right, level + 1);
        recursion(root->left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) 
	{
        recursion(root, 1);
        return result;
    }

private:
    vector<int> result;
};

/*
풀이법 :
right 노드부터 후위순회 하면서 값을 넣는다.
트리의 깊이가 결국 문제에서 원하는 배열의 길이랑 연관이 있으므로
다음 깊이에서 우선 읽는 후위 값을 넣고, nums의 길이로 다른 노드의
val이 들어갈 수 없게하고, 오직 right side 값만 들어가게 한데
*/