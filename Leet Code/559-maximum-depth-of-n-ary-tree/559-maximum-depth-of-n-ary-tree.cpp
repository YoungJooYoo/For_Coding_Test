/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) 
    {
        if (root == nullptr) {
            return 0;
        }
        
        int depth = 0;
        
        for (const auto& child : root->children) {
            depth = max(depth, maxDepth(child));
        }
        
        return depth + 1; // depth가 바닥부터 시작하면저 + 1씩 누적되어 최종 root에 도달하면  tree의 총 높이가 나온다 (depth)
    }
};