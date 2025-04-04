class Solution 
{
public:
    TreeNode* lcaDeepestLeaves(TreeNode* const root) const 
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        assert(root->val >= MIN_VAL && root->val <= MAX_VAL);
        const int leftDepth  = getDepth(root->left);
        const int rightDepth = getDepth(root->right);
        
        if (leftDepth == rightDepth)
        {
            return root;
        }
        else if (leftDepth > rightDepth)
        {
            return lcaDeepestLeaves(root->left);
        }
        else
        {
            return lcaDeepestLeaves(root->right);
        }
    }
    
private:
    int getDepth(const TreeNode* const root) const 
    {
        if (root == nullptr)
        {
            return 0;
        }

        assert(root->val >= MIN_VAL && root->val <= MAX_VAL);
        const int leftDepth  = getDepth(root->left);
        const int rightDepth = getDepth(root->right);
        
        return std::max(leftDepth, rightDepth) + 1;
    }
    
    enum 
    {
        MIN_VAL = 0,
        MAX_VAL = 1000
    };
};

// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/?envType=daily-question&envId=2025-04-04

/*

**1123. 가장 깊은 리프 노드의 최소 공통 조상**

**난이도:** 중간

**문제 설명:**  
이진 트리의 루트가 주어질 때, 트리의 가장 깊은 리프 노드들의 최소 공통 조상(Lowest Common Ancestor, LCA)을 반환하세요.

**참고 사항:**

- 이진 트리의 노드가 리프(leaf)임은 해당 노드가 자식 노드를 갖지 않을 때에만 해당됩니다.
- 트리의 루트 노드의 깊이는 0입니다. 노드의 깊이가 d라면, 그 자식 노드들의 깊이는 d+1입니다.
- 노드 집합 S의 최소 공통 조상은, S의 모든 노드가 그 노드를 루트로 하는 서브트리에 포함되는, 가장 깊이가 큰 노드 A를 의미합니다.

---

**예제 1:**

- **입력:** root = [3,5,1,6,2,0,8,null,null,7,4]
- **출력:** [2,7,4]
- **설명:**  
  그림에서 노드 값이 2인 노드를 반환합니다 (노란색으로 표시됨). 파란색으로 표시된 노드들은 트리의 가장 깊은 리프 노드들입니다.  
  참고로, 노드 6, 0, 8도 리프 노드이지만, 이들의 깊이는 2이고, 노드 7과 4의 깊이는 3입니다.

---

**예제 2:**

- **입력:** root = [1]
- **출력:** [1]
- **설명:**  
  루트 노드가 트리에서 가장 깊은 노드이며, 자기 자신이 최소 공통 조상입니다.

---

**예제 3:**

- **입력:** root = [0,1,3,null,2]
- **출력:** [2]
- **설명:**  
  트리에서 가장 깊은 리프 노드는 2이며, 노드 하나의 최소 공통 조상은 자기 자신입니다.

---

**제약 조건:**

- 트리의 노드 수는 [1, 1000] 범위에 있습니다.
- 0 <= Node.val <= 1000
- 트리의 모든 노드 값은 서로 다릅니다.

---

**참고:**  
이 문제는 865번 문제 "Smallest Subtree With All The Deepest Nodes"와 동일합니다.
*/
